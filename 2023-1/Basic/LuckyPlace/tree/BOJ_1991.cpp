#include <iostream>
using namespace std;

char lc[27];
char rc[27];

void preorder(char cur)
{
	cout << cur;
	if (lc[cur - 'A' + 1] != NULL)
		preorder(lc[cur - 'A' + 1]);
	if (rc[cur - 'A' + 1] != NULL)
		preorder(rc[cur - 'A' + 1]);
}

void inorder(char cur)
{
	if (lc[cur - 'A' + 1] != NULL)
		inorder(lc[cur - 'A' + 1]);
	cout << cur;
	if (rc[cur - 'A' + 1] != NULL)
		inorder(rc[cur - 'A' + 1]);
}

void postorder(char cur)
{
	if (lc[cur - 'A' + 1] != NULL)
		postorder(lc[cur - 'A' + 1]);
	if (rc[cur - 'A' + 1] != NULL)
		postorder(rc[cur - 'A' + 1]);
	cout << cur;
}

int main(void)
{
	int n;
	cin >> n;
	while (n--)
	{
		char C, L, R;
		cin >> C >> L >> R;
		if (L != '.')
			lc[C - 'A' + 1] = L;			// 그냥 C - 'A'하면 0이므로 +1해준다
		if (R != '.')
			rc[C - 'A' + 1] = R;
	}
	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
	return 0;
}