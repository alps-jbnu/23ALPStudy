#include <bits/stdc++.h>

using namespace std;

int tree[50];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, C, W; cin >> N >> C >> W;
    int maxVal = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> tree[i];
        maxVal = max(maxVal, tree[i]);
    }
    long long answer = 0;
    for(int j = 1; j <= maxVal; j++)
    {
        long long temp = 0;
        for(int i = 0; i < N; i++)
        {
            if(tree[i] < j) continue;
            int cutCount, sellCost;
            int remain = tree[i] % j;
            sellCost = (tree[i] - remain) * W;
            if(remain == 0)
            {
                cutCount = tree[i] / j - 1;
            }
            else
            {
                cutCount = tree[i] / j;
            }
            if(sellCost - cutCount * C > 0)
                temp += sellCost - cutCount * C;
        }
        answer = max(answer, temp);
    }
    cout << answer;
    return 0;
}
