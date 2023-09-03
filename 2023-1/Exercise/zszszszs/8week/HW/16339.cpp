#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

const int MAX = 10;

int N;
string s;
// [i, j] 범위 내 연산 최댓값, 최솟값
int maxCache[MAX][MAX];
int minCache[MAX][MAX];

void initialize(void)
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            maxCache[i][j] = INT_MIN;
            minCache[i][j] = INT_MAX;
        }
    }
}

int calculate(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> s;

    initialize();

    int numberCnt = N / 2 + 1;

    for (int i = 0; i < numberCnt; i++)
    {
        maxCache[i][i] = minCache[i][i] = s[i * 2] - '0';
    }

    for (int cnt = 1; cnt < numberCnt; cnt++)
    {
        for (int idx = 0; idx < numberCnt - cnt; idx++)
        {
            for (int i = 1, j = cnt; i <= cnt; i++, j--)
            {
                int opIdx = (idx + cnt - j) * 2 + 1;
                char op = s[opIdx];

                int candidates[4] = {
                    calculate(maxCache[idx][idx + cnt - j], maxCache[idx + i][idx + cnt], op),
                    calculate(maxCache[idx][idx + cnt - j], minCache[idx + i][idx + cnt], op),
                    calculate(minCache[idx][idx + cnt - j], maxCache[idx + i][idx + cnt], op),
                    calculate(minCache[idx][idx + cnt - j], minCache[idx + i][idx + cnt], op)};

                sort(candidates, candidates + 4);

                maxCache[idx][idx + cnt] = max(maxCache[idx][idx + cnt], candidates[3]);
                minCache[idx][idx + cnt] = min(minCache[idx][idx + cnt], candidates[0]);
            }
        }
    }

    int result = maxCache[0][numberCnt - 1];

    cout << result << "\n";

    return 0;
}