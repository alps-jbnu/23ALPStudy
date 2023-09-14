#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        
        int arr[n];
        for(int i=0; i<n; i++) cin >> arr[i];

        long long sum=0;
        vector<int> v;
        for(int i=0; i<n; i++){
            if(arr[i]<=arr[i+1] && i != n-1){
                v.push_back(arr[i]);
            }
            else if(arr[i]>arr[i+1] || i==n-1){
                while(!v.empty()){
                    sum += (arr[i]- v.back());
                    v.pop_back();
                }
            }
        }

        cout << sum << "\n";
    }
    
}
