#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int total, n, sum = 0;
    cin >> total >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        sum += a * b;
    }
    if (sum == total)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}