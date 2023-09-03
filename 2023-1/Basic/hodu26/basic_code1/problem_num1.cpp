#include <iostream>

using namespace std;

int func1(int N){
   int ans=0;
   while (N){
      if (N%3==0 || N%5==0){
         ans += N;
      }
      N--;
   }
   return ans;
}

int main(){
   int N;
   cin >> N;
   cout << func1(N);
   return 0;
}
