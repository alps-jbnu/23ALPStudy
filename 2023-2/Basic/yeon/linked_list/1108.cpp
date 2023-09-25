#include <iostream>
#include <queue>

using namespace std;

int main()
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    queue <int> q;
    
    int n, k;
    cin >> n >> k;
    
    for(int i=0; i<n; i++){
        q.push(i+1);
    }
    
    cout << "<";

    
    while(!q.empty()){
        //queue가 비어있을 때까지 무한반복
        
        for(int i=1; i<k; i++){

            q.push(q.front());
            q.pop();

        }
        
        cout << q.front();
        q.pop();
        
        if(q.size() > 0){ 
            cout << ", ";
        }
        
    }
    
    cout << ">" << '\n';
    
    return 0;
}
