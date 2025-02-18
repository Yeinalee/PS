#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> wine(n);
    vector<int> dp(n);

    for (int i = 0; i < n; i++)
        cin >> wine[i];

    dp[0] = wine[0];
    dp[1] = dp[0] + wine[1];
    dp[2] = max({dp[1], dp[0] + wine[2], wine[1] + wine[2]});
    for (int i = 3; i < n; i++)
        dp[i] = max({dp[i - 1], dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i]});

    cout << dp[n - 1] << '\n';
    return 0;
}