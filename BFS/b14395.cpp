#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
int a, b;

long long getnext(long long x, int op)
{
    if (op == 0)
        return x * x;
    else if (op == 1)
        return x + x;
    else if (op == 2)
        return x - x;
    else if (op == 3)
        return x / x;
}

void bfs()
{
    if (a == b)
    {
        cout << 0 << '\n';
        return;
    }
    vector<char> opt = {'*', '+', '-', '/'};
    queue<pair<long long, string>> q;
    unordered_set<long long> visited;
    q.push({a, ""});
    visited.insert(a);

    while (!q.empty())
    {
        long long now = q.front().first;
        string ans = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            long long next = getnext(now, i);
            if (next == b)
            {
                cout << ans + opt[i] << '\n';
                return;
            }

            if (visited.find(next) == visited.end())
            {
                if (i == 3 && next == 0)
                    continue;
                q.push({next, ans + opt[i]});
                visited.insert(next);
            }
        }
    }

    cout << -1 << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> a >> b;
    bfs();
    return 0;
}