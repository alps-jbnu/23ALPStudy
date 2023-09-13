#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >>n;

    int a;
    vector<int> arr;
    for(int i=0; i<n; i++){
        cin >> a;
        arr.push_back(a); //입력받은 숫자, 배열에 저장
    }

    return 0;
}