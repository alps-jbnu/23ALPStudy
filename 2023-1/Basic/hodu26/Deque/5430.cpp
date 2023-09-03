#include <bits/stdc++.h>

using namespace std;

deque<int> dq;

int main(){
    ios::sync_with_stdio(0);cin.tie();

    int T,n,x,size;
    char trash;
    string p,P;
    bool doR,error=false;

    cin >> T;

    while (T--){
        cin >> p;
        cin >> n;
        cin >> trash;
        for (int i=0;i<n;i++){
            cin >> x >> trash;
            dq.push_back(x);
        }
        if (n == 0){
            cin >> trash;
        }

        doR = false;

        size = p.size();
        for (int i=0;i<size;i++){
            P.push_back(p[i]);
            if (P == "R"){
                doR = !doR;
            }
            else {  // P == "D"
                if (dq.empty()){
                    cout << "error\n";
                    error = true;
                    P.pop_back();
                    break;
                }

                if (doR){  // 배열이 뒤집혀있음
                    dq.pop_back();
                }
                else {  // 배열이 정상적인 순서로 되어있음
                    dq.pop_front();
                }
            }
            P.pop_back();
        }

        if (error){
            error = false;
            continue;
        }

        if (dq.empty()){
            cout << "[]\n";
            continue;
        }

        size = dq.size();
        cout << "[";
        for (int i=0;i<size-1;i++){
            if (doR){  // 배열이 뒤집혀있음
                cout << dq.back() << ",";
                dq.pop_back();
            }
            else {  // 배열이 정상적인 순서로 되어있음
                cout << dq.front() << ",";
                dq.pop_front();
            }
        }
        cout << dq.back() << "]\n";
        dq.pop_back();
    }

    return 0;
}
