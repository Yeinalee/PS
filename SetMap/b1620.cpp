#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m;
    string name, q;
    cin >> n >> m;
    map<string, int> mon;
    vector<string> su;
    for (int i = 1; i <= n; i++)
    {
        cin >> name;
        mon.insert({name, i});
        su.push_back(name);
    }
    while (m--)
    {
        cin >> q;
        try // 번호가 주어지면
        {
            int t = stoi(q);
            cout << su[t - 1] << '\n';
        }
        catch (exception &e) // 이름이 주어지면
        {
            cout << mon.find(q)->second << '\n';
        }
    }
}