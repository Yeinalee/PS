#include <iostream>
#include <vector>
using namespace std;

int check_white(vector<vector<char>> check)
{
    int white_num = 0;
    vector<string> white = {"WBWBWBWB", "BWBWBWBW",
                            "WBWBWBWB", "BWBWBWBW",
                            "WBWBWBWB", "BWBWBWBW",
                            "WBWBWBWB", "BWBWBWBW"};
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (check[i][j] != white[i][j])
                white_num++;
        }
    }
    return white_num;
}

int check_black(vector<vector<char>> check)
{
    int black_num = 0;
    vector<string> black = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
    };
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (check[i][j] != black[i][j])
                black_num++;
        }
    }
    return black_num;
}

int draw(vector<vector<char>> check)
{
    int x = check_white(check);
    int y = check_black(check);
    return x > y ? y : x;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int min = n * m;
    string x;
    vector<string> chass;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        chass.push_back(x);
    }
    for (int i = 0; i <= n - 8; i++)
    {
        for (int j = 0; j <= m - 8; j++)
        {
            vector<vector<char>> check(8, vector<char>(8));
            for (int a = 0; a < 8; a++)
            {
                for (int b = 0; b < 8; b++)
                {
                    check[a][b] = chass[i + a][j + b];
                }
                int m = draw(check);
                if (min > m)
                    min = m;
            }
        }
    }
    cout << min << '\n';
    return 0;
}