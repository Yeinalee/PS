#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, x, t;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if (x > t)
            cout << t << ' ';
    }
    return 0;
}