#include <iostream>
#include <vector>
using namespace std;

//최적화가 관건인듯...
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >>n;

    int a;
    vector<int> v;
    for(int i=0; i<n; i++){
        cin >> a;
        v.push_back(a); //입력받은 숫자, 배열에 저장
    }

    int m;
    cin >>m;

    int cnt=0;
    for(int i=0; i<n; i++){
        int b = v.at(i);
        cout<< "b" << b << endl;
        for(int j=i; j<n; j++){
            int c= v.at(j);
            cout<< "c" << c << endl;
            if(b+c==m){
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}