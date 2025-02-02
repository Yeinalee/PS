#include <iostream>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, answer = 0;
    string in;
    set<string> s;
    cin >> n >> m;
    while (n--)
    {
        cin >> in;
        s.insert(in);
    }
    while (m--)
    {
        cin >> in;
        if (s.find(in) != s.end())
            answer++;
    }
    cout << answer << '\n';
}