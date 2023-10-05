#include <iostream>
#include <stack>

using namespace std;

stack<pair<int, int>> s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, height;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> height;
        while(!s.empty()){
            if(height < s.top().second){
                cout << s.top().first << " ";
                break;
            }
            s.pop();
        }
        if(s.empty()){
            cout << 0 << " ";
        }
        s.push({i + 1, height});
    }
}
