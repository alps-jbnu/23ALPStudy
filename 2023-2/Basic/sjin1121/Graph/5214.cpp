#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, m;
int station_count[101001];
vector<int> station[101001];


int Search_Station_Count() {
    queue<int> q;
    q.push(1);
    station_count[1] = 1;

    while (!q.empty()) {
        int cur_station = q.front();
        q.pop();

        if (cur_station == n)
            return station_count[cur_station];

        for (int i = 0; i < station[cur_station].size(); i++) {
            int next_station = station[cur_station][i];

            if (!station_count[next_station]) {

                if (next_station > n)
                    station_count[next_station] = station_count[cur_station];
                else
                    station_count[next_station] = station_count[cur_station] + 1;
                q.push(next_station);
            }
        }
    }
    return -1;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < k; j++) {
            // station which connected by hypertube
            int input_station;
            cin >> input_station;

            station[i + 100000].push_back(input_station);
            station[input_station].push_back(i + 100000);
        }
    }

    cout << Search_Station_Count() << '\n';
}
