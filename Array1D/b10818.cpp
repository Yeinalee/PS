#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, max, min;
    vector<int> v;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    max = v[0];
    min = v[0];
    for (int i = 1; i < n; i++)
    {
        if (max < v[i])
            max = v[i];
        if (min > v[i])
            min = v[i];
    }
    cout << min << " " << max << endl;
    return 0;
}