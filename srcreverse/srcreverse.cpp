#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <iostream>
using namespace std;

int maxCost = 30;

int func(int k, int x)
{
	vector < vector<int>> p = 
	{
		{},
		{0, 11, 23, 37, 44, 47},
		{0, 21, 29, 38, 40, 61},
		{0, 11, 14, 27, 28, 30}
	};
	if (x < p[1].size()) return p[k][x];
	else return 99999;
}

int main()
{
	vector<int> c = {0, 3, 4, 2};
	vector<vector<pair<int, int>>> s(c.size()); /*table of weights and quantities of the i element*/
	//s.resize(c.size(), {});
	vector<pair<int, int>> sx;
	for (int y = 0; y < maxCost; y++)
	{
		//s[1][y].first = ((y / c[1] + (int)(y % c[1] > 0)) * w[1]);
		//s[1][y].second = ((y / c[1] + (int)(y % c[1] > 0)));
		//s[1].push_back({ ((w / p[1] + (int)(w % p[1] > 0)) * p[1]) , ((w / p[1] + (int)(w % p[1] > 0))) });
		int b = (y / c[1] + (int)(y % c[1] > 0));
		int a = func(1, b);
		s[1].push_back({ a, b });
	}
	for (int k = 2; k < c.size(); k++)
	{
		for (int y = 0; y < maxCost; y++)
		{
			for (int x = 0; x <= (y / c[k] + (int)(y % c[k] > 0)); x++)
			{
				sx.push_back({ func(k, x) + s[k - 1][((y - c[k] * x >= 0) ? (y - c[k] * x) : 0)].first,  x });
			}
			sort(sx.begin(), sx.end());
			s[k].push_back(sx[0]);
			sx.clear();
		}
		printf("DEBUG");
	}

	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < s[i].size(); j++)
		{
			cout << s[i][j].first << ' ' << s[i][j].second << '|';
		}
		cout << "end" << endl;
	}
	return 0;
}
