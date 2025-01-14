#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v;
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    v.push_back(x);
    v.push_back(y);
    v.push_back(w - x);
    v.push_back(h - y);
    cout << *min_element(v.begin(), v.end()) << '\n';
    return 0;
}