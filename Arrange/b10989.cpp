#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    unsigned short x;
    vector<int> v(10001);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v[x]++;
    }
    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 0; j < v[i]; j++)
            cout << i << '\n';
    }
    return 0;
}