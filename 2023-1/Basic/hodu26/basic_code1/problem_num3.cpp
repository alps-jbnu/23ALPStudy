#include <iostream>

using namespace std;

#define MAX 31622  // 10억이하인 제곱근 중 가장 큰 값

int func3(int N){
   int start=0, end=MAX, mid, break_point=0;

   while (1){
      mid = (start+end)/2;

      if (start == end){
         break_point = 1;
      }

      if (N > mid*mid){
         start = mid+1;
      }
      else if (N < mid*mid){
         end = mid-1;
      }
      else {
         return 1;
      }

      if (break_point == 1){
         return 0;
      }
   }
}

int main(){
   int N;
   cin >> N;
   cout << func3(N);
   return 0;
}
