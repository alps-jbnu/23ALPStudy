#include <iostream>

using namespace std;

#define Swap(a,b,t) ( t=a, a=b, b=t )

int arr[5];

int main(){
   ios::sync_with_stdio(0); cin.tie(0);

   int t;
   cin >> arr[0] >> arr[1] >> arr[2];

   for (int i=0;i<3;i++){
      for (int j=i;j<3;j++){
         if (arr[i] < arr[j]){
            Swap(arr[i], arr[j], t);
         }
      }
   }

   if (arr[0] == arr[1]){
      if (arr[1] == arr[2]){
         cout << 10000 + 1000*arr[0];
      }
      else {
         cout << 1000 + 100*arr[0];
      }
   }
   else if (arr[1] == arr[2]){
      cout << 1000 + 100*arr[1];
   }
   else {
      cout << 100*arr[0];
   }
   return 0;
}
