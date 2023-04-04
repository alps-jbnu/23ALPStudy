#include <bits/stdc++.h>
using namespace std;

int use[101];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int arr[k];
    for(int i=0; i<k; i++) cin >> arr[i];

    if(n >= k){
        cout << 0 << "\n";
        return 0;
    }
 
    int o_idx=0, c_idx=0;
    while(c_idx < n){
        if(find(use, use+n, arr[o_idx]) == use+n){
            use[c_idx] = arr[o_idx];
            c_idx++;
        }
        o_idx++;
    }

    int ans = 0;

    for(int i=n; i<k; i++){
        int cur = arr[i];

        //사용할 기기가 콘센트에 없는 경우
        if(find(use, use+n, cur) == use+n){
            pair<int, int> m = {INT_MIN, INT_MIN}; //{다음에 사용할 순서, 기기 번호}

            for(int j=0; j<n; j++){
                pair<int, int> c;
                int pos = find(arr+i,arr+k,use[j]) - arr;

                if(pos == k) c = {INT_MAX, j}; // 앞으로 사용 안 하는 경우
                else c = {pos, j}; // 앞으로 사용하는 경우

                if(c.first > m.first) m= c; // 더 나중에 사용하는 기기인 경우
            }
            use[m.second] = cur;
            ans++;
        }
    }
    cout << ans << "\n";
}
