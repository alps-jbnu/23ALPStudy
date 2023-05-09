#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;
int N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    while(N--){
        deque<int> dq;      //result: 21
        int n;
        string func,arr;
        cin>>func>>n>>arr;  //RDD 4 [1,2,3,4]
        string num;         //need for num > 9
        for(char i:arr){
            if(i>='0'&&i<='9') num+=i;
            else if (!num.empty()){
                dq.push_back(stoi(num));
                num.clear();
            }
        }
        bool rev=0; //i.c. of reverse: false
        bool err=0; //i.c. of error: false
        for(char i:func){
            if (i=='R') rev=!rev;   //0->1->0->...
            else{
                if (dq.empty()){
                    err=1;
                    break;
                }
                rev?dq.pop_back():dq.pop_front();
            }
        }
        if(err) cout<<"error\n";
        else {
            cout << "[";
            if (rev)
                reverse(dq.begin(), dq.end());
            for (int i = 0; i < dq.size(); i++) {
                cout<<dq.at(i);
                if (i != dq.size() - 1) cout << ",";
            }
            cout << "]\n";
        }
    }
}