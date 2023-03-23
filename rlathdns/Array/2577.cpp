#include <iostream>
#include <string>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[10]={};
    int a,b,c;
    int res;
    cin >> a >> b >> c;
    res = a*b*c;
    string s = to_string(res);
    
    for(char c : s){
        arr[c-'0']++;//char 형에서는 문자열 '0'을 빼는것과 48을 빼는것이 같은 의미임.
    }
    for(int i = 0; i<=9; i++){
        cout << arr[i] <<"\n";
    }
    
}
