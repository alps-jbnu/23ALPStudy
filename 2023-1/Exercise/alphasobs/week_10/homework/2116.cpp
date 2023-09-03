#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define pdi pair<double, int>
const int MAX = 1000 + 1;
using namespace std;

int N;
vector<pdi> vec;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        double t, s; cin >> t >> s;
        vec.push_back({ (t / s), i });
    }
    sort(vec.begin(), vec.end());
    
    for(int i = 0; i < N; i++)
    {
        cout << vec[i].second << " ";
    }

    return 0;
}