#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m;

int arr[10];
int num[10];
int check[10];

void seq(int len) {
    if (len == m) {
        for (int i = 0; i < m; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (check[i] == 0) {
            arr[len] = num[i];
            check[i] = 1;
            seq(len + 1);
            check[i] = 0;
        }
    }

    return;
}

int main() {
    scanf_s("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf_s("%d", &num[i]);

    sort(num, num + n);

    seq(0);

    return 0;
}