#include <iostream>
using namespace std;
int main()
{
    int n, i = 666, num = 0;
    cin >> n;
    while (true)
    {
        int six = 0;
        int j = i;
        while (j != 0)
        {
            if (j % 10 == 6)
            {
                six++;
            }
            else
                six = 0;

            if (six == 3)
            {
                num++;
                if (num == n)
                {
                    cout << i << '\n';
                    return 0;
                }
                break;
            }
            j /= 10;
        }
        i++;
    }
}