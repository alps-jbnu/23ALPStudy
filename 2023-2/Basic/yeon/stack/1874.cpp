#include <iostream>
#include <stack>
#include <vector> //결과값 넣어줄 것

using namespace std;

int main()
{
    
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);    
    
    int t;
    cin >> t;
    
    vector <char> v;
    stack <int> s;
    
    int k = 1; //입력값과 비교
    
    for(int i=0; i<t; i++){
        
        int tmp;
        cin >> tmp;
        
        while(k <= tmp){
            s.push(k);
            k++;
            v.push_back('+');
        }
        
        if(s.top() == tmp){ //top과 입력값이 같을 경우 pop
            s.pop();
            v.push_back('-');
        } else{ //불가능한 경우
            cout << "NO" << '\n';
            return 0;
        }
    }
    
    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }

    return 0;
}
