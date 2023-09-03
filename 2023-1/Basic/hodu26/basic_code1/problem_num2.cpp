#include <iostream>

using namespace std;

int func2(int arr[], int N){
   int start=0, end=N-1;

   while (start != end){
      if (arr[start] + arr[end] > 100){
         end--;
      }
      else if (arr[start] + arr[end] < 100){
         start++;
      }
      else {
         return 1;
      }
   }
   return 0;
}

int main(){
   int N;
   cin >> N;
   int arr[N];

   for (int i=0;i<N;i++){
      cin >> arr[i];
   }

   cout << func2(arr, N);
   return 0;
}
