#include <iostream>

using namespace std;

int arr[13];

int main(){
   ios::sync_with_stdio(0); cin.tie(0);

   int n, j=0, min=100, sum=0;

   for (int i=0;i<7;i++){
      cin >> n;

      if (n%2 == 1){
         arr[j] = n;
         j++;
      }
   }

   while (j--){
      if (arr[j] < min){
         min = arr[j];
      }
      sum += arr[j];
   }

   if (sum == 0){
      cout << -1;
   }
   else {
      cout << sum << '\n' << min;
   }

   return 0;
}
