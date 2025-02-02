#include <iostream>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, answer = 0;
    string s;
    set<string> see;
    set<string> seehear;
    cin >> n >> m;
    while (n--)
    {
        cin >> s;
        see.insert(s);
    }
    while (m--)
    {
        cin >> s;
        if (see.find(s) != see.end())
        {
            answer++;
            seehear.insert(s);
        }
    }
    cout << answer << '\n';
    for (auto name : seehear)
        cout << name << '\n';
}