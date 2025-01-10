#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    int v[n + 1];
    for (int i = 1; i <= n; i++)
    {
        v[i] = i;
    }

    while (m--)
    {
        int l, r;
        cin >> l >> r;

        while (l < r)
        {
            swap(v[l], v[r]);
            l++;
            r--;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}