#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

vector<int> alphabet(26);

int strfry(string f, string s)
{
    int i;
    if(f.size() != s.size()) 
	  {
        return 0;
    }
    for(i = 0; i < f.size(); i++)
    {
        alphabet[f[i] - 'a']++;
        alphabet[s[i] - 'a']--;
    }
    for(i = 0; i < 26; i++)
    {
        if(alphabet[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, i;
	string f, s;
	
	cin >> n;
	
	for(i = 0; i < n; i++)
	{
		fill(alphabet.begin(), alphabet.end(), 0);
		cin >> f >> s;
		if(strfry(f, s) == 0)
		{
			cout << "Impossible\n";
		}
		else
		{
			cout << "Possible\n";
		}
	}
	return 0;
}

/*알파벳 세트를 두개 둬서 일일히 서로 if문으로 확인하는 것도 가능.*/
