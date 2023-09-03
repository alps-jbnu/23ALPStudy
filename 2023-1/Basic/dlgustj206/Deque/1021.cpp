#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int left, right, cnt=0;
    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        dq.push_back(i);
    }

    while(m--){
        int x;
        cin>>x;

        for(int i=0; i<dq.size(); i++){
            if(dq[i]==x){
                left=i;
                right=dq.size()-i;
                break;
            }
        }

        if(left<right){
            while(1){
                if(dq.front()==x){
                    dq.pop_front();
                    break;
                }
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        }
        else{
            while(1){
                if(dq.back()==x){
                    cnt++;
                    dq.pop_back();
                    break;
                }
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }
    }
    cout<<cnt;
}