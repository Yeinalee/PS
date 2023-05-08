#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
string Str[1001][1001];
int main()
{
	int R, C;
	vector<string> Vec;
	int Answer = 0;
	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		string S;
		cin >> S;
		for (int j = 0; j < C; j++)
		{
			Str[i][j] = S[j];
		}
	}
	for (int i = 0; i < C; i++)
	{
		string S = "";
		for (int j = 0; j < R; j++)
		{
			S += Str[j][i];
		}
		Vec.push_back(S);
	}
	for (int i = 0; i < Vec.size(); i++)
	{
		Vec[i].erase(Vec[i].begin());
	}
	for (int i = 0; i < (R - 1); i++)
	{
		set<string> SET;
		bool Flag = true;
		for (int j = 0; j < Vec.size(); j++)
		{
			if (SET.find(Vec[j]) == SET.end())
			{
				SET.insert(Vec[j]);
			}
			else
			{
				Flag = false;
				break;
			}
		}
		if (Flag)
		{
			for (int j = 0; j < Vec.size(); j++)
			{
				Vec[j].erase(Vec[j].begin());
			}
			Answer++;
		}
		else
		{
			break;
		}
	}
	cout << Answer << endl;

	return 0;
}