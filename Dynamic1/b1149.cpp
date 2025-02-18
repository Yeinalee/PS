#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x;
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    for (int i = 1; i < n; i++)
    {
        cost[i][0] += min(cost[i - 1][1], cost[i - 1][2]);
        cost[i][1] += min(cost[i - 1][0], cost[i - 1][2]);
        cost[i][2] += min(cost[i - 1][0], cost[i - 1][1]);
    }

    cout << min({cost[n - 1][0], cost[n - 1][1], cost[n - 1][2]}) << '\n';
    return 0;
}