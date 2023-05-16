#include <bits/stdc++.h>
#define ll long long int
const int MAX = 200000 + 1;
using namespace std;

string str;
int Q;
int arr[26][MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
    cin >> Q;
    
    for(int i = 0; i < str.size(); i++)
    {
        if (i != 0) 
        {
            for (int j = 0; j < 26; j++)
            {
                arr[j][i] = arr[j][i - 1];
            }
	    }
        arr[str[i] - 'a'][i]++;
    }
    
    for(int i = 0; i < Q; i++)
    {
        char ch; cin >> ch;
        int l, r; cin >> l >> r;

        int temp = ch - 'a';
        int p1 = 0, p2 = arr[temp][r];

        if(l > 0) p1 = arr[temp][l - 1];

        cout << p2 - p1 << "\n";
    }
	
	return 0;
}