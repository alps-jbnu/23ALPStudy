#include <iostream>
using namespace std;

int head=0, tail=0;
int queue[100001];

void push(int x){
    queue[tail++]=x;
}

void pop(){
    if(head==tail) cout<<-1<<"\n";
    else cout<<queue[head++]<<"\n";
}

void size(){
    cout<<tail-head<<"\n";
}

void empty(){
    if(head==tail) cout<<1<<"\n";
    else cout<<0<<"\n";
}

void front(){
    if(head==tail) cout<<-1<<"\n";
    else cout<<queue[head]<<"\n";
}

void back(){
    if(head==tail) cout<<-1<<"\n";
    else cout<<queue[tail-1]<<"\n";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    while(n--){
        string s;
        cin>>s;
        if(s=="push"){
            int x;
            cin>>x;
            push(x);
        }
        else if(s=="pop") pop();
        else if(s=="size") size();
        else if(s=="empty") empty();
        else if(s=="front") front();
        else if(s=="back") back();
    }
}

/*
STL 사용

#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    queue<int> q;

    while(n--){
        string s;
        cin>>s;
        if(s=="push"){
            int x;
            cin>>x;
            q.push(x);
        }
        else if(s=="pop"){
            if(q.empty()) cout<<-1<<"\n";
            else{
                cout<<q.front()<<"\n";
                q.pop();
            }
        }
        else if(s=="size") cout<<q.size()<<"\n";
        else if(s=="empty"){
            if(q.empty()) cout<<1<<"\n";
            else cout<<0<<"\n";
        }
        else if(s=="front"){
            if(q.empty()) cout<<-1<<"\n";
            else cout<<q.front()<<"\n";
        }
        else if(s=="back"){
            if(q.empty()) cout<<-1<<"\n";
            else cout<<q.back()<<"\n";
        }
    }
}
*/