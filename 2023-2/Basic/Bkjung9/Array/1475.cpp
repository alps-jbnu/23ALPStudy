#include<iostream>
#include<string>
#include<algorithm> 
using namespace std;
 
int main(void){
    string str;
    cin >> str;
            
    int arr[10] = {0};
 
    for(int i=0; i< str.size(); i++){
        arr[str[i] - '0']++; //문자열의 각 문자는 ASCII 코드로 표현되므로, '0'을 빼주면 해당 문자가 나타내는 숫자를 얻을 수 있다.
    }
 
    int num =0;
    for(int i=0; i< 10; i++){
        if(i!=9 && i!=6) num = max(num, arr[i]);
    }
    
    cout << max(num, (arr[6] + arr[9] + 1) /2);
    return 0;    
}
Colored by Color Scripter
