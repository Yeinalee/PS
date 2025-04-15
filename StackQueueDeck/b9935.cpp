#include <iostream>
#include <string>

using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string get;
    string bomb;
    cin >> get >> bomb;
    string result = "";

    for (char ch : get)
    {
        result += ch;
        if (result.size() >= bomb.size())
        {
            bool isMatch = true;
            for (int i = 0; i < bomb.size(); i++)
            {
                if (result[result.size() - bomb.size() + i] != bomb[i])
                {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch)
            {
                result.erase(result.end() - bomb.size(), result.end());
            }
        }
    }

    if (result.size() == 0)
        cout << "FRULA" << '\n';
    else
        cout << result << '\n';
    return 0;
}