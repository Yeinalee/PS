#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr(8);

void sol(int now)
{
    if (m == now)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            arr[now] = i;
            if (now > 0 && arr[now - 1] > arr[now])
                continue;
            sol(now + 1);
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