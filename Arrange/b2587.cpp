#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v;
    int x;
    float sum = 0;
    for (int i = 0; i < 5; i++)
    {

        cin >> x;
        v.push_back(x);
        sum += x;
    }
    sort(v.begin(), v.end());
    cout << sum / 5 << '\n'
         << v[2] << '\n';
    return 0;
}