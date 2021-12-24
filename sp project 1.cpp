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
