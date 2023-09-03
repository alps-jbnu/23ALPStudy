#include <bits/stdc++.h>

using namespace std;

vector<int> inpt;
int lotto[13];

void lotto_recursion(int floor, int cur){

    for (int i=cur+1;i<(int)inpt.size();i++){

        lotto[floor] = inpt[i];

        if (floor == 6){
            for (int j=1;j<=6;j++){
                cout << lotto[j] << ' ';
            }
            cout << '\n';
        }
        else {
            lotto_recursion(floor+1,i);
        }
    }

    return ;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int k,num;

    while (true){
        cin >> k;

        if (k == 0) return 0;

        for (int i=0;i<k;i++){
            cin >> num;
            inpt.push_back(num);
        }

        sort(inpt.begin(),inpt.end());

        lotto_recursion(1,-1);

        cout << '\n';

        while (!inpt.empty()) inpt.pop_back();
    }
    
    return 0;
}
