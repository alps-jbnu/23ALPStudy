#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <list>
#include <tuple>
#include <stdlib.h>
using namespace std;

#define X first
#define Y second

/*
* 1. mid를 중심으로 왼쪽 부분배열의 최대값
* 2. mid를 중심으로 오른쪽 부분배열의 최대값
* 3. mid를 포함한 부분배열의 최대값
* 셋 중 가장 큰 값을 출력 
*/

using ll = long long;
int N;
ll arr[100001];
ll psum[100001]; // 부분 배열의 합

ll solve(int lt, int rt) {
    if (lt == rt) return arr[lt] * arr[lt];

    int mid = (lt + rt) / 2;
    ll ret = max(solve(lt, mid), solve(mid + 1, rt));

    // 처음엔 l = mid, r = mid+1인 상태로 인덱스 1 차이
    int l = mid;
    int r = mid + 1;
    ll mn = min(arr[l], arr[r]);
    ret = max(ret, (psum[r] - psum[l - 1]) * mn);

    while (lt < l || r < rt) {
        // r < rt는 없어도 될듯 
        // arr[r+1]이 a[l-1]보다 크다면 오른쪽으로 확장 
        if (r < rt && (lt == l || arr[l - 1] < arr[r + 1])) {
            r++;
            mn = min(mn, arr[r]);
        }
        // arr[l-1]이 a[r+1]보다 크다면 왼쪽으로 확장 
        else {
            l--;
            mn = min(mn, arr[l]);
        }
        // 확장된 값으로 ret 다시 계산
        ret = max(ret, (psum[r] - psum[l - 1]) * mn);
    }

    return ret;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        psum[i] = psum[i - 1] + arr[i];
    }

    cout << solve(1, N);

    return 0;
}
