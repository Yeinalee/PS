#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int f, s, g, u, d;

void bfs()
{
    queue<int> q;
    vector<int> visited(f + 1, -1);
    vector<int> dy = {u, -d};
    q.push(s);
    visited[s] = 0;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < 2; i++)
        {
            int next = now + dy[i];
            if (next >= 1 && next <= f && visited[next] == -1)
            {
                visited[next] = visited[now] + 1;
                q.push(next);
            }
            if (next == g)
            {
                cout << visited[next] << '\n';
                return;
            }
        }
    }
    cout << "use the stairs" << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> f >> s >> g >> u >> d;
    if (s == g)
    {
        cout << 0 << '\n';
        return 0;
    }
    bfs();
    return 0;
}