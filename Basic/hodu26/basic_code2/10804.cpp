#include <iostream>

using namespace std;

#define Swap(a,b,t) ( t=a, a=b, b=t )

#define mix_num 10

int card[23] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

int main(){
   ios::sync_with_stdio(0); cin.tie(0);

   int a,b,t;
   for (int i=0;i<mix_num;i++){
      cin >> a >> b;

      for (int j=0; j<(b-a+1)/2; j++){
         Swap(card[a+j-1],card[b-j-1],t);
      }
   }

   for (int i=0;i<20;i++){
      cout << card[i] << ' ';
   }
   return 0;
}
