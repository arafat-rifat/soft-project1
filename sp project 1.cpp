#include <iostream>
using namespace std;
string removeComments(string str)
{
    string result = " ";
    int length = str.length();
    bool m_comment = false;
    bool s_comment = false;
    int space_count = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '/' && str[i + 1] == '/')
        {
            s_comment = true, i++;
        }
        else if (s_comment && str[i] == '\n')
        {
            s_comment = false;
        }
        else if (str[i] == '/' && str[i + 1] == '*')
        {
            m_comment = true, i++;
        }
        else if (m_comment && (str[i] == '*' && str[i + 1] == '/'))
        {
            m_comment = false, i++;
        }
        else if (s_comment || m_comment)
        {
            continue;
        }
        else
        {
            result += str[i];
        }
    }
    return result;
}
string remove_space(string str)
{
    int length = str.length();
    string result;
    int space_count = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] == ' ')
        {
            space_count++;
            cout << "space at " << i << "th position" << endl;
        }
        else
        {
            if (space_count >= 1)
                result += ' ';
            result += str[i];
            space_count = 0;
        }
    }
    return result;
}
string resolve_macro(string str)
{
    int length = str.length();
    string result;

    string macName;
    bool macFound = false;
    char macrovalue;
    bool macro = false;
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '#' && str[i + 1] == 'd')
        {
            macro = true;
        }
        if (macro && !macFound && str[i] == ' ')
        {
            int temp = i + 1;
            while (str[temp] != ' ')
            {
                macName += str[temp++];
                macFound = true;
            }
        }
        if (macro && str[i] == '\n')
        {
            macrovalue = str[i - 1];
            macro = false;
        }
        if (macFound && str[i] == macName[0] && str[i + 1] == macName[1] && str[i + 2] == macName[2])
        {
            result += macrovalue;
            i += 2;
            continue;
        }
        result += str[i];
    }
    cout << "Macname: " << macName << endl;
    return result;
}
#define max 5;
int main()
{
    string str = "/*Test program */\n"
                 "#define max 5\n int main()  \n"
                 "       {    \n"

                 "   // variable declaration \n     int a, b, c; \n"
                 "   /* This is a test \n"
                 "              multiline\n"
                 "              comment for \n"
                 "              testing */      \n "
                 "       a = b + c;      \n int val = max "
                 " }     \n ";
    //string str = "Hello //Isnat\n    ";
    string removedComment = removeComments(str);
    string removedSpace = remove_space(removedComment);

    cout << resolve_macro(removedSpace);
    cout << removedComment;
    return 0;
}

