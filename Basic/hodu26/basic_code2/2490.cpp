#include <iostream>

using namespace std;

#define Swap(a,b,t) ( t=a, a=b, b=t )

int arr[5];

int main(){
   ios::sync_with_stdio(0); cin.tie(0);

   int T=3, N, s, score;

   while (T--){
      score = 0; N = 4;

      while (N--){
         cin >> s;
         score += s;
      }

      if (score == 4){
         cout << "E" << '\n';
      }

      if (score == 3){
         cout << "A" << '\n';
      }

      if (score == 2){
         cout << "B" << '\n';
      }

      if (score == 1){
         cout << "C" << '\n';
      }

      if (score == 0){
         cout << "D" << '\n';
      }
   }
   return 0;
}
