#include <iostream>

using namespace std;

int func4(int N){
   int flag = 1;

   while (flag <= N){
      flag *= 2;
   }

   return flag/2;
}

int main(){
   int N;
   cin >> N;
   cout << func4(N);
   return 0;
}
