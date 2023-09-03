#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string s;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> s;

	stack<char> S;

	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == 'P' && s[i + 1] == 'P' && s[i + 2] == 'A' && s[i + 3] == 'P') {
			S.push('P');
			i = i + 3;
		}
		else {
			S.push(s[i]);
		}

		if (S.size() >= 4) {
			char S1 = S.top(); S.pop();
			char S2 = S.top(); S.pop();
			char S3  = S.top(); S.pop();
			char S4 = S.top(); S.pop();

			if (S4 == 'P' && S3 == 'P' && S2 == 'A' && S1 == 'P') {
				S.push('P');
			}
			else {
				S.push(S4);
				S.push(S3);
				S.push(S2);
				S.push(S1);
			}
		}
	}

	if (S.size() == 1) {
		cout << "PPAP";
	}
	else if (S.size() == 4) {
		char S1 = S.top(); S.pop();
		char S2 = S.top(); S.pop();
		char S3 = S.top(); S.pop();
		char S4 = S.top(); S.pop();
		if (S4 == 'P' && S3 == 'P' && S2 == 'A' && S1 == 'P') {
			cout << "PPAP";
		}
	}
	else {
		cout << "NP";
	}

}


