#include <iostream>

using namespace std;

int main(){
   ios::sync_with_stdio(0); cin.tie(0);

   // an+1 = 2an -1 or 2an+1

   int n,sum = 1;
   cin >> n;

   for (int i=1;i<n;i++){
      if (i%2 == 0){
         sum = sum*2 - 1;
      }
      else {
         sum = sum*2 + 1;
      }

      if (sum > 10007){
         sum %= 10007; 
      }
   }

   cout << sum%10007;

   return 0;
}
