#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <iostream>
using namespace std;

int skiFunc(vector<int> buy, vector<int> sell, vector<int> care, int x, int y)
{
	int summCare = 0;
	for (int i = 1; i <= (y - x); i++)
	{
		summCare += care[i];
	}
	return buy[x] + summCare - sell[y-x];
}

int main()
{
		vector<int> ui = {0, 10, 9, 8, 7, 6, 5, 4, 3};
		vector<int> ai = {0, 20, 10, 50, 20, 80, 40, 20, 50};
		vector<vector<int>> s;
		s.resize(9, vector<int>(9));
		for (int y = 1; y < 9; y++)
		{
			for (int x = 1; x <= y; x++)
			{
				int summai = 0;
				for (int i = x; i <= y; i++)
				{
					summai += ai[i];
				}
				s[y][x] = 10000 + 50 * ui[x] + 50 * ui[x] * summai;
			}
		}
		return 0;
}