#include <iostream>
#include <string>
using namespace std;

int how = 0;

int resursion(string &s, int l, int r)
{
    how++;
    if (l >= r)
        return 1;
    else if (s[l] != s[r])
        return 0;
    else
        return resursion(s, l + 1, r - 1);
}

int isPelindrome(string s)
{
    return resursion(s, 0, s.length() - 1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    string s;
    while (t--)
    {
        how = 0;
        cin >> s;
        cout << isPelindrome(s) << ' ' << how << '\n';
    }
    return 0;
}