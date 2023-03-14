#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> cardlist(20);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i, n, m;
	
	for(i = 0; i < 20; i++)
	{
		cardlist[i] = i+1;
	}
	
	for(i = 0; i < 10; i++)
	{
		cin >> n >> m;
		reverse(cardlist.begin() + (n-1), cardlist.begin() + m);
	}
	
	for(i = 0; i < 20; i++)
	{
		cout << cardlist[i] << " ";
	}
	
	return 0;
}

/* 리스트 만들어놓고 하기
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> cardlist= 
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
12, 13, 14, 15, 16, 17, 18, 19, 20};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i, n, m;
	
	for(i = 0; i < 10; i++)
	{
		cin >> n >> m;
		reverse(cardlist.begin() + (n-1), cardlist.begin() + m);
	}
	
	for(i = 0; i < 20; i++)
	{
		cout << cardlist[i] << " ";
	}
	return 0;
}
*/
