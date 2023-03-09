#include <iostream>

using namespace std;

int main(){
   ios::sync_with_stdio(0); cin.tie(0);

   long long int A,B;
   cin >> A >> B;

   if (A == B){
      cout << 0;
      return 0;
   }

   if (A > B){
      cout << A-B-1 << '\n';

      for (long long int i=B+1;i<A;i++){
         cout << i << ' ';
      }
   }
   else {
      cout << B-A-1 << '\n';

      for (long long int i=A+1;i<B;i++){
         cout << i << ' ';
      }
   }

   return 0;
}
