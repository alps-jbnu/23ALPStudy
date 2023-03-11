#include <iostream>

using namespace std;

#define Swap(a,b,t) ( t=a, a=b, b=t )

int arr[5];

int main(){
   ios::sync_with_stdio(0); cin.tie(0);

   int A,B,C,t;

   cin >> arr[0] >> arr[1] >> arr[2];

   for (int i=0;i<3;i++){
      for (int j=i+1;j<3;j++){
         if (arr[i] > arr[j]){
            Swap(arr[i],arr[j],t);
         }
      }
   }

   cout << arr[0] << ' ' << arr[1] << ' ' << arr[2];

   return 0;
}
