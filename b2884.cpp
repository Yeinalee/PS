#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int h, m;
    std::cin >> h >> m;

    if (m >= 45)
        m -= 45;
    else
    {
        m = 60 - (45 - m);
        if (h == 0)
            h = 23;
        else
            h -= 1;
    }
    cout << h << " " << m << endl;
    return 0;
}