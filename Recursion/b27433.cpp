#include <iostream>
using namespace std;

long int factorial(int x)
{
    if (x <= 1)
        return 1;
    return x * factorial(x - 1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int x;
    cin >> x;
    cout << factorial(x) << '\n';
    return 0;
}