#include <iostream>
#include<stack>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int people_num;
  cin>>people_num;

  stack<pair<int,int>> st;
  int now,cnt_same_height=0;
  long long  cnt_pair=0;
  
  for(int i=0; i<people_num ; ++i){
    cin>>now;

    cnt_same_height=1;
    while(!st.empty() && st.top().first < now){
      cnt_pair += st.top().second;
      st.pop();
    }

    if(!st.empty() ){
      if(st.top().first== now){
        cnt_pair += st.top().second;
        cnt_same_height = (st.top().second +1 );
        if(st.size() >1)
          ++cnt_pair;

        st.pop();
      }else{
        ++cnt_pair;
      }
    }
    
    st.push(make_pair(now, cnt_same_height));
  }

  cout<<cnt_pair<<'\n';
  return 0;
}
