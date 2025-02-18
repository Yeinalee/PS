#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    long long answer = 0;
    cin >> n;

    vector<vector<long long>> dp(101, vector<long long>(10, 0));

    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j > 0)
                dp[i][j] += dp[i - 1][j - 1];
            if (j < 9)
                dp[i][j] += dp[i - 1][j + 1];
            dp[i][j] %= 1000000000;
        }
    }
    for (int j = 0; j <= 9; j++)
    {
        answer += dp[n][j];
        answer %= 1000000000;
    }
    cout << answer << '\n';

    return 0;
}