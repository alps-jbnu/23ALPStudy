#include <bits/stdc++.h>

using namespace std;

queue<pair<int,int>> procedure;

void hanoiTop_recursion(int disk, int A, int B){  // move_num -> return 2*hanoiTop_recursion(disk-1) + 1
    if (disk == 1) return procedure.push({A,B});

    hanoiTop_recursion(disk-1, A, 6-A-B);
    procedure.push({A,B});
    hanoiTop_recursion(disk-1, 6-A-B, B);
    return ;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int disk;

    cin >> disk;

    hanoiTop_recursion(disk, 1, 3);

    cout << procedure.size() << '\n';

    while (!procedure.empty()){
        cout << procedure.front().first << ' ' << procedure.front().second << '\n';
        procedure.pop();
    }

    return 0;
}
