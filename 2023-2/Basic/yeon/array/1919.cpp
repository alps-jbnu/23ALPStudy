#include <iostream>

using namespace std;

int arr[2][26] = {};

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int cnt = 0;

    for(char i: s1) arr[0][i-'a']++;
    for(char j: s2) arr[1][j-'a']++;

    for(int i=0; i<26; i++){

        int a = arr[0][i];
        int b = arr[1][i];

        if(a != b){
            if(a > b) cnt += a-b;
            else cnt += b-a;
        }
    }

    cout << cnt;

    return 0;
    
}
