#include <iostream>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, x, same = 0;
    set<int> aset;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        aset.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        if (aset.find(x) != aset.end()) // 차집합
            same++;
    }
    cout << n + m - 2 * same << '\n';
}