#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    char board[500000];
    char first; cin >> first;
    board[0] = first;
    int switchCount = 1;
    for(int i = 1; i < N; i++)
    {
        cin >> board[i];
        if(board[i - 1] != board[i])
            switchCount++;
    }
    cout << switchCount / 2 + 1;
    return 0;
}
