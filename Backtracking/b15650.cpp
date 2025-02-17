#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr(8);
vector<bool> used(9);

void sol(int now)
{
    if (now == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    else
    {
        int i;
        for (i = 1; i <= n; i++)
        {
            if (!used[i])
            {
                used[i] = true;
                arr[now] = i;
                if (now > 0 && arr[now - 1] > arr[now])
                {
                    used[i] = false;
                    continue;
                }
                sol(now + 1);
                used[i] = false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    sol(0);
    return 0;
}