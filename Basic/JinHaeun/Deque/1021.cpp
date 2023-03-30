#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
  
	deque<int> dq;
	
	int n;
	cin >> n;
	
	int m;
	cin >> m;
	
	for(int i=1; i<=n; i++)
	{
		dq.push_back(i);    //큐채우기  
	}
	
	int cnt = 0;
	int index;
	for(int i=1; i<=m; i++)
	{
		int num;
		cin >> num;
		
		for(int j=0; j<dq.size(); j++)
		{
			if(dq[j] == num)         //덱은 STL에서 인덱스 접근 가능함  
			{
				index = j;         // 위치 파악을 위한 인덱스 구하기  
				break;
			}
		}
		
		if(dq.size() - index > index)    //전체 사이즈에서 자신 위치 뺀 것보다 작으면 앞에껄 뒤로 보냄  
		{
			while(1)
			{
				if(dq.front() == num) break;
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;
			}
			dq.pop_front();			
		}
		else
		{
			while(1)
			{
				if(dq.front() == num) break;
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
			dq.pop_front();
		}
	}
	
	cout << cnt;

}
