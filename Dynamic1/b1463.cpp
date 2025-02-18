#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minVal = 10000;

void answer(int n, int num)
{
    if (minVal < num)
        return;
    while (n == 1)
    {
        if (minVal > num)
            minVal = num;
        return;
    }

    if (!(n % 3))
        answer(n / 3, num + 1);

    if (!(n % 2))
        answer(n / 2, num + 1);

    answer(n - 1, num + 1);
}

int main()
{
    int n;
    cin >> n;
    answer(n, 0);
    cout << minVal << '\n';
    return 0;
}