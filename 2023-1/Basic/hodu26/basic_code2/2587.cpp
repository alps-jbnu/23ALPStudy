#include <iostream>

using namespace std;

#define Swap(a,b,t) ( t=a, a=b, b=t )

int arr[13];

int main(){
   ios::sync_with_stdio(0); cin.tie(0);

   int t, sum=0;
   for (int i=0;i<5;i++){
      cin >> arr[i];
   }

   for (int i=0;i<5;i++){
      for (int j=i;j<5;j++){
         if (arr[i] < arr[j]){
            Swap(arr[i],arr[j],t);
         }
      }
      sum += arr[i];
   }

   cout << sum/5 << '\n' << arr[2];
   return 0;
}
