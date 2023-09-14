#include <iostream>
using namespace std;

void fun(int n,int k) {
	if (n < 0) {
		return;
	}
	else if (n == 0) {
		for (int i = 0; i < k * 4; i++) printf("_");
		printf("\"재귀함수가 뭔가요?\"\n");
		for (int i = 0; i < k * 4; i++) printf("_");
		printf("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n");
		for (int i = 0; i < k * 4; i++) printf("_");
		printf("라고 답변하였지.\n");
	}
	else {
		for (int i = 0; i < k * 4; i++) printf("_");
		printf("\"재귀함수가 뭔가요?\"\n");
		for (int i = 0; i < k * 4; i++) printf("_");
		printf("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n");
		for (int i = 0; i < k * 4; i++) printf("_");
		printf("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n");
		for (int i = 0; i < k * 4; i++) printf("_");
		printf("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n");
		fun(n - 1, k + 1);
		for (int i = 0; i < k * 4; i++) printf("_");
		printf("라고 답변하였지.\n");
	}
}

int main(void) {
	printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
	int n = 0;
	cin >> n;
	fun(n,0);
}
