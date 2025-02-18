// 점화식 dp[i+1][j+1] = min(dp[i][j], dp[i][j+1])
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x;
    cin >> n;
    vector<vector<int>> triangle(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cin >> x;
            triangle[i].push_back(x);
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (j == 0)
                triangle[i][j] += triangle[i - 1][j];
            else if (j == i)
                triangle[i][j] += triangle[i - 1][j - 1];
            else
                triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
        }
    }

    sort(triangle[n - 1].begin(), triangle[n - 1].end());
    cout << triangle[n - 1][n - 1] << '\n';
    return 0;
}