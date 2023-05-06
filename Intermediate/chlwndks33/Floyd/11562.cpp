// baekjoon -  11562번 백양로 브레이크

// #include <iostream>
// #include <algorithm>
// using namespace std;

// const int INF = 0x3f3f3f3f;
// int n,m,num;
// int d[251][251];

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> n >> m;
//     for(int i=1; i<=n; i++) {
//         fill(d[i], d[i]+n+1, INF);
//         d[i][i] = 0;
//     }
//     while(m--) {
//         int a, b, c;
//         cin >> a >> b>> c;
//         if(c==1) { //양방향통행이면 비용 x
//             d[a][b] = 0;
//             d[b][a] = 0;
//         }
//         else { // 일방통행이면 그 도로만 비용 x 반대는 비용 1로 설정
//             d[a][b] = 0;
//             d[b][a] = 1; 
//         }
//     }
//     for(int k=1; k<=n; k++) {
//         for(int i=1; i<=n; i++) {
//             for(int j=1; j<=n; j++) {
//                 if(d[i][j] > d[i][k]+ d[k][j]) {
//                     d[i][j] = d[i][k] + d[k][j];
//                 }
//             }
//         }
//     }

//     cin >> num;
//     while(num--) {
//         int x,y;
//         cin >> x >> y;
//         cout << d[x][y] << '\n';
//     }
    
// }