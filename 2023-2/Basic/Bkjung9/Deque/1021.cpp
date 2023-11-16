#include <iostream>
#include <deque>

using namespace std;

int main(int argc, char**argv) {

	ios::sync_with_stdio(0);
	cin.tie(0);
		
	deque<int> DQ;
	int N, M;
	int left, right;
	int cnt = 0;
	
	cin >> N >> M;
	
	for(int i=1; i<=N; i++){
		DQ.push_back(i);
	}
	

	while(M--){
		int num;
		cin >> num;
		
		for(int i=0; i<DQ.size(); i++){
			
			if(DQ[i] == num){
				left = i;
				right = DQ.size()-i;
				break;
				
			}
		}
		
		if(left<=right){
			while(1){
				if(DQ.front()==num)
					break;

				DQ.push_back(DQ.front());
				DQ.pop_front();
				cnt++;
				
			}
			DQ.pop_front();
		}
		
		else{
			cnt++;
			while(1){
				if(DQ.back()==num)
					break;
	
				DQ.push_front(DQ.back());
				DQ.pop_back();
				cnt++;
				
			}
			DQ.pop_back();
		}

	}
	
	cout << cnt;
	
	return 0;
}
