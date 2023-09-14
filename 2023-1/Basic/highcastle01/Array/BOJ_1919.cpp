#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> falphabet(26);
vector<int> salphabet(26);

int checking(string f, string s)
{
	int i, samecnt = 0, sum = 0;
	
	for(i = 0; i < f.size(); i++)
	{
		falphabet[f[i] - 'a']++;
	}
	for(i = 0; i < s.size(); i++)
	{
		salphabet[s[i] - 'a']++;
	
	}
	
	for(i = 0; i < 26; i++)
	{
		if(falphabet[i] != salphabet[i])
		{
			sum += abs(falphabet[i] - salphabet[i]);
		}
	}
	
	return sum;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string f, s;
	
	cin >> f >> s;
	
	cout << checking(f, s);
	return 0;
}

/* 굳이 알파벳 벡터로 넘겨서 할 필요 없이 스트링으로도 할 수 있다.
그리고 처음에 1. 값이 같은 부분의 값을 저장하고 2.알파벳 벡터속 값들의 총합에서 중복되는 1.의 값을 * 2한 뒤 빼주면 될 줄 알았는데 아니었었다.
*/
