#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        vector<char> stack;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                stack.push_back('(');
            }
            else if (s[i] == ')')
            {
                if (!stack.empty() && stack.back() == '(')
                {
                    stack.pop_back();
                }
                else
                {
                    stack.push_back(')');
                    break;
                }
            }
        }
        if (stack.empty())
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}