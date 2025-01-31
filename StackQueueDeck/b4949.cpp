#include <iostream>
#include <vector>
using namespace std;
bool isBalance(string s)
{
    vector<char> balance;
    for (char c : s)
    {
        if (c == '(' || c == '[')
            balance.push_back(c);
        else if (c == ')')
            if (!balance.empty() && balance.back() == '(')
                balance.pop_back();
            else
                return false;
        else if (c == ']')
            if (!balance.empty() && balance.back() == '[')
                balance.pop_back();
            else
                return false;
    }
    if (balance.empty())
        return true;
    else
        return false;
}

int main()
{
    while (1)
    {
        string s;
        getline(cin, s);
        if (s == ".")
            break;
        bool b = isBalance(s);
        if (b)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
    return 0;
}