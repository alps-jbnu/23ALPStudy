#include <iostream>
using namespace std;

int arr[129][129]; 
int white = 0;
int blue = 0;

void fc(int, int, int);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cin >> arr[i][j];
        }
    }

    fc(0, 0, n);

    cout << white << '\n';
    cout << blue << '\n';
}

void fc(int x, int y, int k){
    bool cut = false;
    int first_color = arr[x][y];

    for (int i = x; i < x + k;i++){
        for (int j = y; j < y + k;j++){
            if(arr[i][j] != first_color){ //중간에 다른색이 나오면 자름
                cut = true;
                break; 
            }
        }
    }

    if(cut){
        fc(x, y, k / 2);
        fc(x, y + k / 2, k / 2);
        fc(x + k / 2, y, k / 2);
        fc(x + k / 2, y + k / 2, k / 2);
    }
    else{
        if(first_color == 1)
            blue++;
        else
            white++;
    }    
}