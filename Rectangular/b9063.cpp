#include <iostream>
using namespace std;
int main()
{
    int n, x, y, minx = 0, maxx = 0, miny = 0, maxy = 0;
    cin >> n;
    cin >> x >> y;
    minx = maxx = x;
    miny = maxy = y;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        if (minx > x)
            minx = x;
        if (maxx < x)
            maxx = x;
        if (miny > y)
            miny = y;
        if (maxy < y)
            maxy = y;
    }
    cout << (maxx - minx) * (maxy - miny) << '\n';
    return 0;
}