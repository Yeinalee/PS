#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr(7);
vector<bool> used(8);

void sol(int now)
{
    if (m == now)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (!used[i])
            {
                // used[i] = true;
                arr[now] = i;
                sol(now + 1);
                // used[i] = false;
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