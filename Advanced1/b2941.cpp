#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<string> cro = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    string s;
    int idx;
    cin >> s;
    for (int i = 0; i < cro.size(); i++)
    {
        while (true)
        {
            idx = s.find(cro[i]);
            if (idx == string::npos) // 문자열을 못 찾았을 경우
                break;
            s.replace(idx, cro[i].length(), "*");
        }
    }
    cout << s.size() << '\n';
    return 0;
}