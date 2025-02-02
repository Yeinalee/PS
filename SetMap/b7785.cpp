#include <iostream>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string name, in;
    set<string> log;
    cin >> n;
    while (n--)
    {
        cin >> name >> in;
        if (in == "enter")
            log.insert(name);
        else if (in == "leave")
            log.erase(name);
    }
    for (auto it = log.rbegin(); it != log.rend(); it++)
    {
        cout << *it << '\n';
    }
    return 0;
}