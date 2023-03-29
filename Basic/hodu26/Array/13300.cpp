#include <bits/stdc++.h>

using namespace std;

int students[3][13];  // [sex][grade]

int main(){
   ios::sync_with_stdio(0);cin.tie();

   int N,K,S,Y, rooms=0;
   cin >> N >> K;

   while (N--){
      cin >> S >> Y;
      students[S][Y] += 1;
   }

   for (int i=0;i<2;i++){
      for (int j=1;j<=6;j++){
         if (students[i][j] % K == 0){
            rooms += students[i][j]/K;
         }
         else {
            rooms += students[i][j]/K + 1;
         }
      }
   }

   cout << rooms;

   return 0;
}
