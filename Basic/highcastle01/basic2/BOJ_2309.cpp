#include<iostream>
#include<algorithm>

using namespace std;

int nanjang[9];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i, j, k, sum = 0;
	
	for(i = 0; i < 9; i++)
	{
		cin >> nanjang[i];
		sum += nanjang[i];
	}
	
	sort(nanjang, nanjang + 9);
	
	for (i = 0; i < 8; i++) 
	{
		for (j = 1; j < 9; j++) 
		{

			if (sum - (nanjang[i] + nanjang[j]) == 100) 
			{

				for (k = 0; k < 9; k++) 
				{
					if (k == i || k == j) 
					{
						continue;
					}
					cout << nanjang[k] << '\n';
				}
				return 0;
			}
		}
	}
	
	return 0;
}

/* 컴파일러에서는 되는데 백준에서는 틀렸습니다가 뜨는 풀이..
#include<iostream>
#include<algorithm>

using namespace std;

vector<int> nanjang(9);

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
	int i, j, su, sum = 0;
	
	for(i = 0; i < 9; i++)
	{
		cin >> nanjang[i];
		sum += nanjang[i];
	}
	
	for(i = 0; i < 8; i++)
	{
		for(j = i + 1; j < 9; j++)
		{
			if(sum - (nanjang[i] + nanjang[j]) == 100)
			{
				nanjang.erase(nanjang.begin() + j);
				nanjang.erase(nanjang.begin() + i);
			}
		}
	}
	
	sort(nanjang.begin(), nanjang.end());
	
	for(i = 0; i < nanjang.size(); i++)
	{
		cout << nanjang[i] << "\n";
	}
	
	return 0;
}
