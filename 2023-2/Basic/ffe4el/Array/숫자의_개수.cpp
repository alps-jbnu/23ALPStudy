#include <iostream>
#include <string>
using namespace std;

int main(){
    int a,b,c;
    cin >> a;
    cin >> b;
    cin >> c;

    int cnt = a*b*c;
    int result[10];

    for(int i=0; i<10;i++){ //0으로 초기화
        result[i]=0;
    }
    
    string cnt1 = to_string(cnt);
    for(int i=0; i<cnt1.size(); i++ ){
        for(int j=0; j<10; j++){
            if(int(cnt1[i]-48)==j){ //아스키코드 변환(문자열 to 정수)
                result[j] = result[j]+1;
            }
        }
    }

    for(int i=0; i<10; i++){
        cout << result[i] << endl;
    }



    return 0;
}