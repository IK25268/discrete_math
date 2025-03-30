#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <iostream>
using namespace std;

const int INF = 9999;

int main()
{
	vector<vector<int>> matr = { 
		{0}, 
		{INF, INF, 1, 0, 6, 12}, 
		{INF, 13, INF, 4, 12, 15}, 
		{INF, 15, 11, INF, 15, 15}, 
		{INF, 9, 11, 8, INF, 14}, 
		{INF, 9, 8, 6, 10, INF} 
	};
	int LB = 0;
	vector<int> prohibrows = {1, 2, 3};
	vector<int> prohibcols = {2, 3, 5};
	vector<pair<int, int>> prohibroutes = { {2, 1}, {3, 2}, {3, 4}, {5, 3} };
	vector<int> ai(6, INF);
	vector<int> bi(6, INF);
	for (auto const &iter: prohibroutes)
	{
		matr[iter.first][iter.second] = INF;
	}
	for (auto const& iterprohibcols : prohibcols)
	{
		for (int y = 1; y < 6; y++)
		{
			matr[y][iterprohibcols] = INF;
		}
	}
	for (int iterai = 1; iterai < 6; iterai++)
	{
		if (find(prohibrows.begin(), prohibrows.end(), iterai) == prohibrows.end()) ai[iterai] = *min_element(matr[iterai].begin(), matr[iterai].end());
	}
	vector<int> minbi = {};
	for (int iterbi = 1; iterbi < 6; iterbi++)
	{
		if (find(prohibcols.begin(), prohibcols.end(), iterbi) == prohibcols.end())
		{
			for (int iterai = 1; iterai < 6; iterai++)
			{
				if (ai[iterai] != INF) 
				{
					minbi.push_back(matr[iterai][iterbi] - ai[iterai]);
				}
			}
			bi[iterbi] = *min_element(minbi.begin(), minbi.end());
		}
		minbi.clear();
	}
	for (int summ = 1; summ < 6; summ++)
	{
		if (ai[summ] != INF) LB += ai[summ];
		if (bi[summ] != INF) LB += bi[summ];
	}
	cout << LB;
	
	return 0;
}