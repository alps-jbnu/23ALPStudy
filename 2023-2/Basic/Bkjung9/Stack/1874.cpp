#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main(){
    stack<int> s;
    vector<char> v;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int set = 1;
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        while(set <= x){ //1부터 x까지 '+'를 삽입하면서 숫자를 스택에 삽입
            v.push_back('+');
            s.push(set);
            set++;
        }

        if(x == s.top()){ //x가 top과 같다면, pop하면서 '-'삽입
            s.pop();
            v.push_back('-');
        } 

        else{
            cout << "NO";
            return 0;
        }
    }
    for(int i = 0; i < v.size(); i++){ //벡터 함수 출력
            cout << v[i] << "\n";
        }
}
