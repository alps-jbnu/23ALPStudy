#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

struct A {
    int data; // 원소값
    int pos;  // 원소가 위치한 인덱스
};

int main() {
    /* cin, cout 입출력 속도 향상 */
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    deque<A> dq;
    for (int i = 0; i < N; ++i) {
        if (!dq.empty() && i == dq.front().pos + L) // 나갈 타이밍이 된 친구는 앞에서 빠져나가도록 삭제해준다. pop_front()
            dq.pop_front();
        while (!dq.empty() && dq.back().data > arr[i]) // arr[i] 가 들어오게 됨으로써 arr[i]보다 커서 앞으로 최소값 될 일이 절대 없는 기존 deque 안의 원소들은 삭제해준다. pop_back()
            dq.pop_back();
        dq.push_back({ arr[i], i }); // arr[i] 을 추가한다. (위 pop_back()으로 인하여 arr[i]보다 더 큰건 다 삭제했으므로 오름차순 정렬을 유지한 채로 뒤에 추가되게 된다.)
        cout << dq.front().data << " "; // deque 의 맨앞 원소를 출력하면 그게 바로 현재 구간(i-L+1 ~ i)에서의 최소값 
    }
}
