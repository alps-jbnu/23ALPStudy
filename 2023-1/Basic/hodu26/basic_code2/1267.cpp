#include <iostream>

using namespace std;

int main(){
   ios::sync_with_stdio(0); cin.tie(0);

   int N,Y=0,M=0,time=0;
   cin >> N;

   while (N--){
      cin >> time;

      Y += 10*(time/30)+10;
      M += 15*(time/60)+15;
   }

   if (Y > M){
      cout << "M " << M;
   }
   else if (Y == M){
      cout << "Y " << "M " << Y;
   }
   else {
      cout << "Y " << Y;
   }

   return 0;
}
