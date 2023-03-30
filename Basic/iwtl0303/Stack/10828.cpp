#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x)
{
  dat[pos] = x;
  pos++;
}

void pop()
{
  if (pos != 0)
  {
    pos--;
    cout << dat[pos] << "\n";
  }
  else
    cout << -1 << "\n";
}

int top()
{
  if (pos != 0)
  {
    return dat[pos - 1];
  }
  else return -1;
}

void size()
{
  cout << pos << "\n";
}

void empty()
{
  if (pos == 0)
    cout << 1 << "\n";
  else
    cout << 0 << "\n";
}


int main(void)
{
  int n,num;
  string cmd;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> cmd;
    if (cmd == "push") {
      cin >> num;
      push(num);
    }
    else if (cmd == "pop") pop();
    else if (cmd == "size") size();
    else if (cmd == "empty") empty();
    else cout << top()<<"\n";
  }
}