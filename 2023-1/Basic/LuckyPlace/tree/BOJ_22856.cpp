#include <iostream>
using namespace std;

int lc[100001];
int rc[100001];
int p[100001];				// iterative하게 중위 순회를 구현하기 위해 parent선언
bool vis[100001];			// iterative하게 중위 순회를 구현하기 위해 vis선언

int cnt;

//void inorder(int cur)		// 아마 불가능
//{
//	if (lc[cur] != 0)
//		inorder(lc[cur]);
//	cout << cur << ' ';
//	if (rc[cur] != 0)
//		inorder(rc[cur]);
//}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--)
	{
		int C, L, R;
		cin >> C >> L >> R;
		if (L != -1)
			lc[C] = L;
		if (R != -1)
			rc[C] = R;
		if (L != -1)
			p[L] = C;
		if (R != -1)
			p[R] = C;
	}
	int cur = 1;		// cur == root(1)
	int rightmost = 1;		// 가장 오른쪽 아래의 노드, 만약 루트 노드만 존재하면 루트 노드가 rightmost이므로 1로 초기화
	while (rc[cur] != 0)
	{
		rightmost = rc[cur];
		cur = rightmost;
	}
	//rightmost에서 멈추려면 recursive하게 구현은 불가능하므로 iterative하게 구현
	cur = 1;
	while (true)
	{
		vis[cur] = true;
		cnt++;
		if (lc[cur] != 0 && !vis[lc[cur]])
			cur = lc[cur];
		else if (rc[cur] != 0 && !vis[rc[cur]])
			cur = rc[cur];
		else                                     // 왼쪽 오른쪽 둘다 방문했거나 못 가는 경우
		{
			if (cur == rightmost)		  // 못가는데 현재 rightmost면 break
				break;
			else                                // 그것도 아니면 부모 노드로 올라가기
				cur = p[cur];
		}
	}
	cout << cnt - 1;				//	맨 처음 root에서 시작할 때 불필요하게 1이 추가되므로 1을 빼준다
	return 0;
}