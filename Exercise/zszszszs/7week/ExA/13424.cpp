#define MAX 987654321
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int node, edge, s, e, val, test, num;
int arr[101][101];

void floydWarshall()
{
    for (int k = 1; k <= node; k++)
        for (int i = 1; i <= node; i++)
            for (int j = 1; j <= node; j++)
                if (arr[i][j] > arr[i][k] + arr[k][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> test;
    for (int t = 0; t < test; t++)
    {
        cin >> node >> edge;
        for (int i = 1; i <= node; i++)
            for (int j = 1; j <= node; j++)
            {
                if (i == j)
                    arr[i][j] = 0;
                else
                    arr[i][j] = MAX;
            }
        for (int i = 0; i < edge; i++)
        {
            cin >> s >> e >> val;
            arr[s][e] = val;
            arr[e][s] = val;
        }
        floydWarshall();
        cin >> num;
        vector<int> v;
        int result = MAX, idx;
        for (int i = 0; i < num; i++)
        {
            cin >> val;
            v.push_back(val);
        }
        for (int k = 1; k <= node; k++)
        {
            int temp = 0;
            for (int i = 0; i < num; i++)
                temp += arr[k][v[i]];
            if (result > temp)
            {
                result = temp;
                idx = k;
            }
        }
        cout << idx << '\n';
    }
    return 0;
}