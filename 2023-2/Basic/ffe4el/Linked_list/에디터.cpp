#include <iostream>
using namespace std;

const int MX = 600001;
int dat[MX], pre[MX], nxt[MX];
int unused=1;

void insert(int addr, char word){
    dat[unused]=word; //새로운 원소 생성
    pre[unused]=addr; //새 원소의 pre 값에 삽입할 위치의 주소를 대입
    nxt[unused]=nxt[addr]; //새 원소의 nxt 값에 삽입할 위치의 nxt값을 대입
    //삽입할 위치의 nxt값이 -1이 아니라면, 삽입할 위치의 다음 원소의 pre값을 새 원소의 주소로 변경
    if(nxt[addr] != -1) pre[nxt[addr]]=unused; 
    //삽입할 위치의 nxt값을 새원소의 주소값으로 변경
    nxt[addr]=unused;
    
    unused++;
}

void erase(int addr){
    nxt[pre[addr]] = nxt[addr];
    if(nxt[addr]) pre[nxt[addr]] = pre[addr];
}

// void traverse(){
//     int cur = nxt[0];
//     while(cur!=-1){
//         cout << dat[cur];
//         cur = nxt[cur];
//     }
//     cout << "\n";
// }


int main(){
    string w;
    cin >>w;
    int cursor = 0;

    for(int i=0; i<w.size(); i++){
        insert(i, w[i]);
        cursor++;
    }

   int m;
   cin >> m;

   int leng=w.size();//문자총 길이

    for(int i=0; i<m; i++){
        char b;//명령어
        cin >> b;
        if(b=='P'){
            char c;
            cin >>c;
            cout << "c:" <<c;
            insert(cursor,c);
            leng++;
        }
        else if(b=='L'){
            if(cursor != 0){
                cursor--;
                cout << "L cursor:" <<cursor;
            }
        }
        else if(b=='D'){
            if(cursor != leng-1){
                cursor++;
                cout << "D cursor:" <<cursor;
            }
        }
        else if(b=='B'){
            if(cursor != 0 && cursor != leng-1){
                erase(cursor);
            }
            leng--;
        }
    }



    // traverse();


    return 0;
}