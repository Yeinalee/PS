#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v(30, 0);
    int x;
    for (int i = 0; i < 28; i++)
    {
        cin >> x;
        v[x - 1] = 1;
    }
    for (int i = 0; i < 30; i++)
    {
        if (v[i] == 0)
            cout << i + 1 << endl;
    }
    return 0;
}