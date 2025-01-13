#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool group(string s)
{
    vector<int> v(26, 0);
    v[s[0] - 'a']++;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != s[i - 1])
        {
            if (v[s[i] - 'a'] != 0)
            {
                // cout << s << s[i] << '\n';
                return false;
            }

            else
                v[s[i] - 'a']++;
        }
    }
    // cout << s << '\n';
    return true;
}

int main()
{
    int n, ans = 0;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (group(s))
            ans++;
    }
    cout << ans << '\n';
    return 0;
}