#include <iostream>
#include <vector>
using namespace std;

int n;
vector<long long> pado;

void p(int x)
{
    if (x > n)
    {
        cout << pado[n] << '\n';
        return;
    }
    else
    {
        if (x >= 0 && x <= 3)
            pado.push_back(1);
        else if (x >= 4 && x <= 5)
            pado.push_back(2);
        else
            pado.push_back(pado[x - 1] + pado[x - 5]);
        p(x + 1);
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        p(pado.size());
    }
    return 0;
}