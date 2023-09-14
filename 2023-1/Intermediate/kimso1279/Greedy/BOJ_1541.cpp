#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
    
    string str;
    bool flag=false; // f => +, t => -

    cin >> str;

    int sum=0;
    string num;
    for(int i=0; i<=str.size(); i++){
        if(str[i]=='+' || str[i]=='-' || i==str.size()){
            if(flag == false){
                sum += stoi(num);
                num = "";
            }
            else{
                sum -= stoi(num);
                num = "";
            }
            if(str[i] == '-') flag = true;
        }
        else{
            num += str[i];
        }
    }   
    cout << sum << "\n";
}
