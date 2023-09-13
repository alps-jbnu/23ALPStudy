#include <iostream>
using namespace std;

int main(){
    string n;
    cin >> n;

    //0-8까지 갯수 1개 초기화, 6은 예외로 2개(6,9 모두 가능하니까)
    int cmp[9] = {1,1,1,1,1,1,2,1,1};//반복문으로도 가능(근데 ㄱㅊ)

    int cnt=1;
    for(int i=0; i<n.size(); i++){
        if(int(n[i]-48)==9){
            // cout << cmp[6] << endl;
            if(cmp[6]-1>=0){
                cmp[6] -= 1;
            }
            else{
                cnt++;
                int cmp[9] = {1,1,1,1,1,1,2,1,1}; //초기화
                cmp[6] -= 1;
            }
        }
        else{
            for(int j=0; j<9; j++){
                if(int(n[i]-48)==j){
                    // cout << cmp[j] <<endl;
                    if(cmp[j]-1>=0){
                        cmp[j] -= 1;
                    }
                    else{
                        cnt++;
                        int cmp[9] = {1,1,1,1,1,1,2,1,1}; //초기화
                        cmp[j] -= 1;
                    }    
                }
            }
        }
    }


    cout<<cnt<<endl;
    


    return 0;
}