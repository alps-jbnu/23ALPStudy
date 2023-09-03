#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define pip pair<int, pii>
const int MAX = 250000 + 1;
using namespace std;

int N, X, sum = 0, result = 0;
int arr[MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> N >> X;
    for(int i = 1; i <= N; i++)
    {
        int num; cin >> num;
        arr[i] += num += arr[i - 1];
    }

    for(int i = X; i <= N; i++)
    {
        int temp = arr[i] - arr[i - X];
        if(sum < temp)
        {
            sum = temp;
            result = 1;
        }
        else if(sum == temp) result++;
    }
    
    if(sum > 0) cout << sum << "\n" << result << "\n";
    else cout << "SAD\n";

	return 0;
}