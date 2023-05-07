#include<bits/stdc++.h>

using namespace std;

void parse(string str, string &tmp, deque<int> &nlist)
{
	int i;
	for(i = 0; i < str.size(); i++)
	{
		if(isdigit(str[i]))
		{
			tmp += str[i];
		}
		else
		{
			if(!tmp.empty())
			{
				nlist.push_back(stoi(tmp));
				tmp = "";
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t, n, i, j, k;
	string p;
	
	cin >> t;
	
	for(i = 0; i < t; i++)
	{
		bool reverse = false, error = false;
		deque<int> nlist;
		string str, tmp = "";
		cin >> p;
		cin >> n;
		cin >> str;
		
		parse(str, tmp, nlist);
		for(char c : p)
		{
			if(c == 'R')
			{
				if(reverse)
				{
					reverse = false;
				}
				else
				{
					reverse = true;
				}
			}
			else if(c == 'D')
			{
				if(nlist.empty())
				{
					error = true;
					break;
				}
				if(reverse)
				{
					nlist.pop_back();
				}
				else if(!reverse)
				{
					nlist.pop_front();
				}
			}
		}
		
		if(error)
		{
			cout << "error\n";
		}
		else
		{
			cout << "[";
			if(reverse && !nlist.empty())
			{
				for(auto i = nlist.rbegin(); i != nlist.rend(); i++)
				{
					if(i == nlist.rend() - 1)
					{
						cout << *i;
					}
					else
					{
						cout << *i << ",";
					}
				}
			}
			else if(!reverse && !nlist.empty())
			{
				for(auto i = nlist.begin(); i != nlist.end(); i++)
				{
					if(i == nlist.end() - 1)
					{
						cout << *i;
					}
					else
					{
						cout << *i << ",";
					}
				}
			}
			cout << "]\n";
		}
	}
	
	return 0;
}
