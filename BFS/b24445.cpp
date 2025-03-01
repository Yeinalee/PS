#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
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

        for (int i = graph[now].size() - 1; i >= 0; i--)
        {
            if (!visited[graph[now][i]])
            {
                visited[graph[now][i]] = cnt++;
                q.push(graph[now][i]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, r, a, b;
    cin >> n >> m >> r;

    graph.resize(n + 1);
    visited.resize(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i < n + 1; i++)
        sort(graph[i].begin(), graph[i].end());

    bfs(r);

    for (int i = 1; i < n + 1; i++)
        cout << visited[i] << '\n';

    return 0;
}