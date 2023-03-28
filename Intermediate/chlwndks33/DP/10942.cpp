    // Baekjoon - 10942번 팰린드롬?

    #include <iostream>
    using namespace std;

    int d [2001][2001];
    int arr[2001];

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int n;
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> arr[i];
        }
        for(int i=1; i<=n; i++) {
            d[i][i] = 1;  //차이가 0 처리
            if(arr[i-1] == arr[i]) d[i-1][i] = 1;  //차이가 1인거 처리
        }
        for(int i=2; i< n; i++) {  //차이가 2부터 n-1까지
            for(int j=1; j <= n-i; j++) {
                int s = j; 
                int t = j + i;
                if(arr[s] == arr[t] && d[s+1][t-1] == 1) {
                    d[s][t] = 1;
                }
            }
        }
        int t;
        cin >> t;
        while(t--) {
            int a,b;
            cin >> a >> b;
            cout << d[a][b] <<'\n';
        }

    }