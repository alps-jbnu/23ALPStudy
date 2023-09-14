#include <iostream>
#include <queue>
#define N 1001
using namespace std;

// N : 정점의 개수, M : 간선의 개수, V : 탐색 시작 정점
int n, m, v;

// f_node : 연결된 간선의 첫 번째 노드
// s_node : 연결된 간선의 두 번째 노드
int f_node, s_node;

// DFS 용 방문한 정점 목록
int DFS_visited[N] = {0};

// BFS 용 방문한 정점 목록
int BFS_visited[N] = {0};

// 그래프 행렬
int graph[N][N] = {0};

// 너비 우선 탐색에 사용할 queue
queue<int> node_queue;

// 깊이 우선 탐색
void DFS(int node){

    // 해당 노드 출력
    cout << node << " ";

    for (int i=1; i<=n; ++i){
        // 입력 받은 노드와 연결된 노드가 있다면
        if (graph[node][i] == 1){
            // 해당 노드가 방문하지 않았던 노드라면
            if (DFS_visited[i] == 0){
                // 해당 노드를 방문한 노드로 기록
                DFS_visited[i] = 1;
                // 깊이 우선 탐색
                DFS(i);
            }
        }
    }
}

// 너비 우선 탐색
void BFS(int node){

    for (int i=1; i<=n; ++i){
        // 입력 받은 노드와 연결된 노드가 있다면
        if (graph[node][i] == 1){
            // 해당 노드가 방문하지 않았던 노드라면
            if (BFS_visited[i] == 0){
                // 연결된 노드는 방문한 노드로 기록
                BFS_visited[i] = 1;
                // 연결된 노드를 queue 에 삽입
                node_queue.push(i);
            }
        }
    }
}

// queue 를 통한 너비 우선 탐색
void queue_navigation(int node){

    // 입력 노드를 queue 에 삽입
    node_queue.push(v);

    // queue 안에 노드가 없을때까지
    while(node_queue.size() != 0){
        // front 에 위치한 노드를 출력한 후
        cout << node_queue.front() << " ";
        // front 노드를 기준으로 너비 우선 탐색
        BFS(node_queue.front());
        // front 노드 제거
        node_queue.pop();
    }
}

int main(){

    // 정점의 개수, 간선의 개수, 탐색 시작 정점 입력
    cin >> n >> m >> v;

    // 간선을 통한 그래프 생성
    for (int i=1; i<=m; ++i){

        // 연결된 간선의 두 노드 입력    
        cin >> f_node >> s_node ;

        // 연결된 간선은 1 로 처리
        graph[f_node][s_node] = 1;
        graph[s_node][f_node] = 1;
    }

    // 시작 정점은 방문한 정점으로 기록
    DFS_visited[v] = 1;
    // 깊이 우선 탐색 시작
    DFS(v);

    cout << endl;

    // 시작 정점은 방문한 정점으로 기록
    BFS_visited[v] = 1;
    // queue 를 통한 너비 우선 탐색 시작
    queue_navigation(v);

    return 0;
}
