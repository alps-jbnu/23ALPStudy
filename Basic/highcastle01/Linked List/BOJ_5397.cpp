#include<bits/stdc++.h>

using namespace std;

const int MX = 10000005;
char dat[MX];
int pre[MX];
int nxt[MX];
int unused = 1;

void insert(int addr, char num)
{
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if(nxt[addr] != -1)
    {
        pre[nxt[addr]] = unused;
    }
    nxt[addr] = unused;
    unused++;
}

void erase(int addr)
{
    nxt[pre[addr]] = nxt[addr];
    if(nxt[addr] != -1)
    {
        pre[nxt[addr]] = pre[addr];
    }
}

void traversal()
{
    int cur = nxt[0];
    while(cur != -1)
    {
        cout << dat[cur];
        cur = nxt[cur];
    }
    cout << '\n';
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	fill(pre, pre+MX, -1);
	fill(nxt, nxt+MX, -1);
	
	int n, i;
	string init;
	
	cin >> n;
	
	for(i = 0; i < n; i++)
	{
		int cursor = 0;
		cin >> init;
		
		for(auto c : init)
		{
			if(c == '<')
			{
				if(pre[cursor] != -1)
				{
					cursor = pre[cursor];
				}
			}
			else if(c == '>')
			{
				if(nxt[cursor] != -1)
				{
					cursor = nxt[cursor];
				}
			}
			else if(c == '-')
			{
				if(pre[cursor] != -1)
				{
					erase(cursor);
					cursor = pre[cursor];
				}
			}
			else
			{
				insert(cursor, c);
				cursor = nxt[cursor];
			}
		}
		traversal();
		fill(dat, dat+MX, -1);
		fill(pre, pre+MX, -1);
		fill(nxt, nxt+MX, -1);
	}
	return 0;
}
