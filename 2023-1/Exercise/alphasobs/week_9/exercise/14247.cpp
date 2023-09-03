#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define pip pair<int, pii>
const int MAX = 100000 + 1;
using namespace std;

ll N, result = 0;
ll height[MAX], arr[MAX];
vector<pii> vec;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> height[i];

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    for(int i = 0; i < N; i++)
        vec.push_back({ arr[i], height[i] });
    sort(vec.begin(), vec.end());

    for(int i = 0; i < N; i++)
    {
        result += vec[i].second + vec[i].first * i;
    }
    cout << result;

    return 0;
}