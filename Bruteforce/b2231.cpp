#include <iostream>
using namespace std;
int main()
{
    int n, sum;
    cin >> n;
    for (unsigned int i = 1; i < 1000000; i++)
    {
        sum = i;
        int j = i;
        while (j / 10 != 0)
        {
            sum += (j % 10);
            j /= 10;
        }
        sum += j;
        if (sum == n)
        {
            cout << i << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
    return 0;
}