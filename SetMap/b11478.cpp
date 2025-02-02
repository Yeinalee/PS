#include <iostream>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    set<string> subset;
    cin >> s; // ababc
    for (int i = 0; i < s.length(); i++)
    {
        string sub = string(1, s[i]);
        for (int j = i; j < s.length(); j++)
        {
            sub += s[j];
            subset.insert(sub);
        }
    }
    cout << subset.size() << '\n';
    return 0;
}