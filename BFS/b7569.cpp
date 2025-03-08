#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Point3D
{
    int x, y, z;
};
int m, n, k;
vector<vector<vector<int>>> map;
queue<Point3D> ripe;
vector<int> dx = {-1, 1, 0, 0, 0, 0};
vector<int> dy = {0, 0, -1, 1, 0, 0};
vector<int> dz = {0, 0, 0, 0, -1, 1};

int bfs()
{
    while (!ripe.empty())
    {
        int cx = ripe.front().x;
        int cy = ripe.front().y;
        int cz = ripe.front().z;
        ripe.pop();
        for (int i = 0; i < 6; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int nz = cz + dz[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && nz >= 0 && nz < k)
            {
                if (map[nz][ny][nx] == 0)
                {
                    ripe.push({nx, ny, nz});
                    map[nz][ny][nx] = map[cz][cy][cx] + 1;
                }
            }
        }
    }
    int max = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < m; l++)
            {
                if (map[i][j][l] == 0)
                    return -1;
                if (max < map[i][j][l])
                    max = map[i][j][l];
            }
        }
    }
    return max - 1;
}

int main()
{
    int x;
    cin >> m >> n >> k;
    map.resize(k, vector<vector<int>>(n, vector<int>(m)));

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < m; l++)
            {
                cin >> x;
                if (x == 1)
                    ripe.push({l, j, i});
                map[i][j][l] = x;
            }
        }
    }
    cout << bfs() << '\n';
    return 0;
}