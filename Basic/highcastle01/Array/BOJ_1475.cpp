#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> check(10);

void checking(int n)
{
    int i, j;
    string nstr;

    nstr = to_string(n);

    for(i = 0; i < nstr.size(); i++)
    {
        check[nstr[i] - '0']++;
    }
    check[6] = (check[6] + check[9] + 1) / 2;
    check[9] = 0;
}

int set()
{
    int i, j, max = 0;

    for(i = 0; i < 10; i++)
    {
        if(max < check[i])
        {
			max = check[i];
        }
    }

    return max;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i, j;
    cin >> n;

    checking(n);

    cout << set();

    return 0;
}
