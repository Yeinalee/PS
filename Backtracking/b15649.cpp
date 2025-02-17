#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<bool> used(9);
vector<int> arr(9);

void permutation(int now)
{
    if (now == m) // 조건 만족
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            arr[now] = i;
            permutation(now + 1); // 가능한 모든 경우의 수 확인
            used[i] = false;      // 백트래킹
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    permutation(0);
    return 0;
}