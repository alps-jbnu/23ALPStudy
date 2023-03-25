#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

struct info {
  int x, y, dir;  // dir=-1: 죽은 물고기
};

info fish[17];
int result = 0;
int arr[4][4];  // 1~16: 물고기, 0: Shark, -1: 죽은 물고기

void move_fish() {
  for (int i = 1; i < 17; i++) {
    int cx = fish[i].x;
    int cy = fish[i].y;
    int cd = fish[i].dir;

    if (cd == -1) continue;  // 죽은 물고기

    int nx, ny;
    int nd = cd;
    for (int j = 0; j < 8; j++) {
      nx = cx + dx[nd];
      ny = cy + dy[nd];
      if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
        int idx = arr[ny][nx];
        if (idx == 0) {  // shark
          nd = (nd + 1) % 8;
          continue;
        }

        // 물고기 자리 교환
        arr[ny][nx] = i;
        fish[i].x = nx;
        fish[i].y = ny;
        fish[i].dir = nd;

        arr[cy][cx] = idx;
        fish[idx].x = cx;
        fish[idx].y = cy;
        break;
      }
      nd = (nd + 1) % 8;
    }
  }
}

void dfs(int y, int x, int dir, int sum) {
  info fdup[17];
  int dup[4][4];
  // 복사
  for (int i = 1; i < 17; i++) fdup[i] = fish[i];
  memcpy(dup, arr, sizeof(dup));

  // 물고기 이동
  move_fish();

  // 상어 이동
  int nx = x;
  int ny = y;
  while (1) {
    nx += dx[dir];
    ny += dy[dir];
    if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
      int idx = arr[ny][nx];
      if (idx == -1) continue;  // 물고기가 없어서 이동 불가
      // 물고기
      int fd = fish[idx].dir;

      // 죽임 처리 + 상어 자리이동
      fish[idx].dir = -1;
      arr[y][x] = -1;
      arr[ny][nx] = 0;
      dfs(ny, nx, fd, sum + idx);

      // 원복
      fish[idx].dir = fd;
      arr[y][x] = 0;
      arr[ny][nx] = idx;
    } else
      break;
  }
  result = max(result, sum);

  // 원복
  memcpy(arr, dup, sizeof(dup));
  for (int i = 1; i < 17; i++) fish[i] = fdup[i];
  return;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("C:/Users/vl619/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("C:/Users/vl619/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int a, b, val;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
      cin >> a >> b;
      arr[i][j] = a;
      fish[a].x = j;
      fish[a].y = i;
      fish[a].dir = b - 1;
    }
  val = arr[0][0];
  int sd = fish[val].dir;
  fish[val].dir = -1;
  arr[0][0] = 0;
  dfs(0, 0, sd, val);
  cout << result;
  return 0;
}

/*
1. (0, 0)에서 시작 및 해당 물고기의 방향을 get
2. 남은 물고기들에서 낮은 번호부터 움직임
    - 1칸 이동
    - 상어 있는 곳 or 경계 벗어난 곳은 이동 불가능
    - 이동 할때 까지 반시계 방향으로 45도 씩 움직임
    - 움직이는 방향에 물고기 있는 경우 그 물고기와 위치 교환
3. 상어가 움직이는데 움직이는 곳에 물고기 없거나 이동방향으로 갈 수 없을 경우 종료
*/