#include <iostream>
#include <algorithm>
using namespace std;


int findNumber(int arr[], int n, int target) {
    int st = 0, en = n - 1;
    int mid = (st + en) / 2;

    while (1) {
        if (en < st) return 0;

        int mid = (st + en) / 2;
        if (arr[mid] > target) en = mid - 1;
        else if (arr[mid] < target) st = mid + 1;
        else if (arr[mid] == target) return 1;
    }

    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, target;
    int arr[100005] = {};

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> target;
        cout << findNumber(arr, N, target) << '\n';
    }


    return 0;
}
