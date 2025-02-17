// 01타일
// 점화식: dp[n] = dp[n-1] + dp[n-2]
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> answer;

void sol(int x)
{
    if (x > n)
        return;
    if (x == 0 || x == 1)
        answer.push_back(1);
    else if (x == 2)
        answer.push_back(2);
    else
        answer.push_back((answer[x - 1] + answer[x - 2]) % 15746);
    sol(x + 1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    sol(0);
    cout << answer[n] << '\n';
    return 0;
}