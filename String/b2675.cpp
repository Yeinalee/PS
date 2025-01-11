#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    string c;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m >> c;
        for (int k = 0; k < c.length(); k++)
        {
            for (int j = 0; j < m; j++)
                cout << c[k];
        }
        cout << endl;
    }
}