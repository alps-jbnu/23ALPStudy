#include <bits/stdc++.h>
using namespace std;

int pre[5001];
int nxt[5001];

vector<int> yolist;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	  
	int n, k, i, len = 0, cursor;
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++)
	{
		pre[i] = (i == 1) ? n : i - 1;
	    nxt[i] = (i == n) ? 1 : i + 1;
	    len++;
	}
	
	i = 1;
  
	for(cursor = 1; len != 0; cursor = nxt[cursor])
	{
	  	if(i == k)
		  {
	        pre[nxt[cursor]] = pre[cursor];
	        nxt[pre[cursor]] = nxt[cursor];
	      
          yolist.push_back(cursor);
          i = 1;
          len--;
      } 
      else 
      {
        i++;
      }
  }
      cout << "<";
  for(i = 0; i < n; i++)
  {
      cout << yolist[i];
      if(i < n - 1)
      {
         cout << ", ";
      }
  }
  cout << ">";
  return 0;
}

//다시 풀어볼 것
