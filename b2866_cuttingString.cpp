#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    string str[1001][1001];
    int answer = 0;
    vector<string> vec;

    int R, C;
    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++)
            str[i][j] = s[j];
    }

    for (int i = 0; i < C; i++)
    {
        string s = "";
        for (int j = 0; j < R; j++)
            s += str[j][i];
        vec.push_back(s);
    }

    for (int i = 0; i < vec.size(); i++)
        vec[i].erase(vec[i].begin());

    for (int i = 0; i < (R - 1); i++)
    {
        set<string> SET;
        bool flag = true;
        for (int j = 0; j < vec.size(); j++)
        {
            if (SET.find(vec[j]) == SET.end())
                SET.insert(vec[j]);
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            for (int j = 0; j < vec.size(); j++)
                vec[j].erase(vec[j].begin());
            answer++;
        }
        else
            break;
    }

    cout << answer << endl;
    return 0;
}