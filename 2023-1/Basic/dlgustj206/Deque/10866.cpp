#include <iostream>
using namespace std;

const int mx=10001;
int dq[2*mx+1];
int head=mx, tail=mx;

void push_front(int x){
    dq[--head]=x;
}

void push_back(int x){
    dq[tail++]=x;
}

void pop_front(){
    if(head==tail) cout<<-1<<"\n";
    else cout<<dq[head++]<<"\n";
}

void pop_back(){
    if(head==tail) cout<<-1<<"\n";
    else cout<<dq[--tail]<<"\n";
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
    else cout<<dq[head]<<"\n";
}

void back(){
    if(head==tail) cout<<-1<<"\n";
    else cout<<dq[tail-1]<<"\n";
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
        if(s=="push_front"){
            int x;
            cin>>x;
            push_front(x);
        }
        else if(s=="push_back"){
            int x;
            cin>>x;
            push_back(x);
        }
        else if(s=="pop_front") pop_front();
        else if(s=="pop_back") pop_back();
        else if(s=="size") size();
        else if(s=="empty") empty();
        else if(s=="front") front();
        else if(s=="back") back();
    }
}