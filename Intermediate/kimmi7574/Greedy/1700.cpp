#include <bits/stdc++.h>
using namespace std;

int n, k;
int schedule[105];
int multiTap[105] = { 0, };
int min_cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		cin >> schedule[i];
	}

	for (int i = 0; i < k; i++) {
		bool flag = false;
		//1) ÀÌ¹Ì ²ÈÇô ÀÖ´Ù¸é pass
		for (int j = 0; j < n; j++) {
			if (multiTap[j] == schedule[i]) {
				flag = true;
				break;
			}
		}

		if (flag)
			continue;

		//2) ÇÃ·¯±× ºóÄ­ÀÌ ÀÖÀ¸¸é ²È±â
		for (int j = 0; j < n; j++) {
			if (multiTap[j] == 0) {	//ºñ¾îÀÖÀ½(=0)
				multiTap[j] = schedule[i];	//ºó ÀÚ¸®¿¡ »õ·Î¿î Àü±âÁ¦Ç° ²ÈÀ½
				flag = true;
				break;
			}
		}
		if (flag)
			continue;

		//3) ºóÄ­ÀÌ ÇÊ¿äÇÑ °æ¿ì
		int last_need = -1;	//°¡Àå ´Ê°Ô ´Ù°¡¿Ã Â÷·Ê
		int index = -1;	//¸ÖÆ¼ÅÇ »¬ ÀÚ¸®

		for (int j = 0; j < n; j++) {
			int tmp = 0;
			for (int t = i + 1; t < k; t++) {
				if (schedule[t] == multiTap[j])
					break;
				tmp++;
			}

			if (tmp > last_need) {
				last_need = tmp;
				index = j;
			}
		}

		multiTap[index] = schedule[i];
		min_cnt++;
	}
	cout << min_cnt << "\n";
}