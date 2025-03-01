#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> visited;
vector<vector<int>> graph;
int cnt = 1;

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = cnt++;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int next : graph[now])
        {
            if (!visited[next])
            {
                visited[next] = cnt++;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, r, a, b;
    cin >> n >> m >> r;

    visited.resize(n + 1, 0);
    graph.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
        sort(graph[i].begin(), graph[i].end());

    bfs(r);

    for (int i = 1; i < n + 1; i++)
        cout << visited[i] << '\n';

    return 0;
}