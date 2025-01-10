#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, i, j;
    cin >> n >> m;
    vector<int> v(n + 1);
    int temp;
    for (int t = 0; t < n + 1; t++)
        v[t] = t;
    for (int t = 0; t < m; t++)
    {
        cin >> i >> j;
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
    cout << v[1];
    for (int t = 2; t < n + 1; t++)
        cout << " " << v[t];
    cout << endl;
    return 0;
}