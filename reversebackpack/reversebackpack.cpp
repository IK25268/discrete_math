#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <iostream>
using namespace std;

int maxCost = 30;

int main()
{
	vector<int> c = { 0, 2, 4, 5, 6 }; /*cost*/
	vector<int> w = { 0, 13, 19, 31, 44 }; /*weight*/
	vector<vector<pair<int, int>>> s(c.size()); /*table of weights and quantities of the i element*/
	//s.resize(c.size(), {});
	vector<pair<int, int>> sx;
	s[1].resize(c[1]);
	for (int y = c[1]; y < maxCost; y++)
	{
		//s[1][y].first = ((y / c[1] + (int)(y % c[1] > 0)) * w[1]);
		//s[1][y].second = ((y / c[1] + (int)(y % c[1] > 0)));
		s[1].push_back({ ((y / c[1] + (int)(y % c[1] > 0)) * w[1]) , ((y / c[1] + (int)(y % c[1] > 0))) });
	}
	for (int i = 2; i < c.size(); i++)
	{
		s[i].resize(c[1]);
		for (int y = c[1]; y < maxCost; y++)
		{
			for (int x = 0; x <= (y / c[i] + (int)(y % c[i] > 0)); x++)
			{
				sx.push_back({ w[i] * x + s[i - 1][((y - c[i] * x >= 0) ? (y - c[i] * x) : 0)].first,  x });
			}
			sort(sx.begin(), sx.end());
			s[i].push_back(sx[0]);
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