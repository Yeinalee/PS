#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j, k;
    cin >> n >> m;
    vector<int> v(n, 0);

    for (int a = 0; a < m; a++)
    {
        cin >> i >> j >> k;
        for (int t = i; t <= j; t++)
            v[t - 1] = k;
    }
    cout << v[0];
    for (int i = 1; i < n; i++)
        cout << " " << v[i];
    cout << endl;
}