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
	vector<int> buy = {100, 115, 120, 130, 135, 130};
	vector<int> sell = {0, 65, 45, 35, 20, 0, 0};
	vector<int> care = {0, 15, 20, 45, 75, 80, 100};	
	vector<vector<pair<int, pair<int, int>>>> s;
	vector<pair<int, pair<int, int>>> smin;
	s.push_back({});
	s[0].push_back({0, {0,0}});
	smin.push_back({0, {0,0}});
	for (int k = 1; k < 7; k++)
	{
		s.push_back({});
		for (int x = 0; x <= k-1; x++)
		{
			s[k].push_back({skiFunc(buy, sell, care, x, k) + smin[x].first, {x , k}});
		}
		if(s[k].size()!=0)sort(s[k].begin(), s[k].end());
		smin.push_back(s[k][0]);
	}
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < s[i].size(); j++)
		{
			cout << s[i][j].first << ' ' << s[i][j].second.first << ' ' << s[i][j].second.second << " | ";
		}
		cout << "end" << endl;
	}
	return 0;
}