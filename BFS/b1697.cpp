#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, k;
vector<int> visited(100002, 0);

void bfs()
{
    queue<int> q;
    q.push(n);
    visited[n] = 0;

    if (k == n)
    {
        cout << 0 << '\n';
        return;
    }
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        vector<int> next;
        next.push_back(now + 1);
        next.push_back(now - 1);
        next.push_back(now * 2);

        for (int i = 0; i < 3; i++)
        {
            if (next[i] < 100001 && !visited[next[i]])
            {
                q.push(next[i]);
                visited[next[i]] = visited[now] + 1;
            }
        }
    }
    cout << visited[k] << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;

    bfs();
    return 0;
}