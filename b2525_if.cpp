#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int h, m, n;
    cin >> h >> m;
    cin >> n;

    h = (h + (m + n) / 60) % 24;
    m = (m + n) % 60;

    cout << h << " " << m << endl;
    return 0;
}