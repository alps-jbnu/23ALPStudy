// Baekjoon - 1541번 잃어버린 괄호

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string exp;
vector<int> vec;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> exp;
    string temp = "";
    for(int i=0; i<exp.size(); i++) {
        if(exp[i]== '+' || exp[i] == '-') { 
            if(i==0)  { //맨 처음으로 - 기호가 나오는 경우 temp에 추가 
                temp+=exp[i];
                continue;
            }
            vec.push_back(stoi(temp));  //temp를 정수형으로 바꿔 벡터에 추가
            temp = exp[i]; 
        }
        else {
            temp += exp[i];
        }
    }
    vec.push_back(stoi(temp));
    
    int sum =0;
    for(int i=0; i<vec.size()-1; i++) {
        if(vec[i]<0 && vec[i+1]>0) { 
            vec[i+1] = vec[i+1]* -1;
        }
    }
    for(int i=0; i<vec.size(); i++) {
        sum += vec[i];
    }
    cout << sum;
}