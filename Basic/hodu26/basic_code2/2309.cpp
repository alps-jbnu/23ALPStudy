#include <iostream>

using namespace std;

#define Swap(a,b,t) ( t=a, a=b, b=t )

int dwarfs_hight[13];
int dwarfs_7[13];

int break_point=0;

void Find_dwarf(int sum, int floor, int dn){

   if (sum == 100 && floor == 7){
      break_point = 1;
      return ;
   }

   for (int i=dn;i<9;i++){

      if (sum+dwarfs_hight[i] <= 100 && floor < 7){
         dwarfs_7[floor] = dwarfs_hight[i];
         Find_dwarf(sum+dwarfs_7[floor], floor+1, i+1);
      }

      if (break_point == 1){
         return ;
      }

      dwarfs_7[floor] = 0;
   }

   return ;
}

int main(){
   ios::sync_with_stdio(0); cin.tie(0);

   int t;
   for (int i=0;i<9;i++){
      cin >> dwarfs_hight[i];
   }

   Find_dwarf(0,0,0);

   for (int i=0;i<7;i++){
      for (int j=i;j<7;j++){
         if (dwarfs_7[i] > dwarfs_7[j]){
            Swap(dwarfs_7[i],dwarfs_7[j],t);
         }
      }
   }

   for (int i=0;i<7;i++){
      cout << dwarfs_7[i] << '\n';
   }

   return 0;
}
