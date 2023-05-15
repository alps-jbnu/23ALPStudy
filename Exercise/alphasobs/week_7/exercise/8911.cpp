#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define pip pair<int, pii>
const int MAX = 250 + 1;
using namespace std;

int T, d = 0;
int dir[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
string str;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> T;
    while(T--)
    {
        int x = 0, y = 0;
        int x_min = 0, y_min = 0, x_max = 0, y_max = 0;
        cin >> str;
        for(int i = 0; i < str.size(); i++)
        {
            char ch = str[i];
            if(ch == 'F')
            {
                x += dir[d][0];
                y += dir[d][1];
            }
            else if(ch == 'B')
            {
                x -= dir[d][0];
                y -= dir[d][1];
            }
            else if(ch == 'L')
            {
                d = (d + 1) % 4;
            }
            else if(ch == 'R')
            {
                d = (d + 3) % 4;
            }

            x_min = min(x, x_min);
            y_min = min(y, y_min);
            x_max = max(x, x_max);
            y_max = max(y, y_max);
        }
        cout << ((x_max - x_min) * (y_max - y_min)) << "\n";
    }

	return 0;
}