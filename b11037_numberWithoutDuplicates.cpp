#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<int> number_list = {};

void make_nls(int maxlen, int cnt, int used, int val)
{
    if (cnt >= maxlen)
        number_list.push_back(val);
    else
    {
        for (int i = 0; i < 9; i++)
        {
            if (used & (1 << i))
                continue;
            make_nls(maxlen, cnt + 1, used | (1 << i), val * 10 + numbers[i]);
        }
    }
}

int main()
{
    vector<long long> arr;
    vector<int> answer;
    int n = -1;
    for (int i = 0; i < 10; i++)
    {
        make_nls(i, 0, 0, 0);
    }

    while (cin >> n)
    {
        if (n >= 987654321)
            answer.push_back(0);
        else
        {
            int start = 0;
            int end = number_list.size();
            while (start + 1 < end)
            {
                int mid = (start + end) / 2;
                if (number_list[mid] <= n)
                    start = mid;
                else
                    end = mid;
            }
            if (number_list[start] <= n)
                answer.push_back(number_list[end]);
        }
    }

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i];

    return 0;
}