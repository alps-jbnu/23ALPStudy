#define x first
#define y second

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double dx[4] = {1, 0, -1, 0};
double dy[4] = {0, 1, 0, -1};

int N;
bool map[202][202];

vector<pair<double, double>> dragon_curves[21];

void print_dc(int idx) {
    for(int i{}; i<dragon_curves[idx].size(); i++) {
        cout<<dragon_curves[idx][i].x<<","<<dragon_curves[idx][i].y<<" ";
    }
    cout<<"\n";
}

void print_map() {
    for(int i{}; i<202; i++) {
        for(int j{}; j<202; j++) {
            cout<<map[i][j];
        }
        cout<<"\n";
    }
}

pair<double, double> rotate(pair<double, double> point, pair<double, double> base) {
    pair<double, double> rotated_point;
    rotated_point.x = (point.y - base.y) * 1 + base.x;
    rotated_point.y = (point.x - base.x) * (-1) + base.y;
    rotated_point = {round(rotated_point.x), round(rotated_point.y)};
    return rotated_point;
}

void dragon_curve(pair<double, double> start, int direction, int generation, int n) {
    dragon_curves[n].push_back(start);
    pair<double, double> end = {start.x + dx[direction], start.y + dy[direction]};
    dragon_curves[n].push_back(end);

    for(int i{1}; i<=generation; i++) { 
        int bef_size = dragon_curves[n].size();
        pair<double, double> end = dragon_curves[n][bef_size-1];
        for(int j{bef_size-2}; j>=0; j--) {
            dragon_curves[n].push_back(rotate(dragon_curves[n][j], end));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // auto test = rotate({0.0, 0.0}, {1.0, 1.0});
    // cout<<test.x<<","<<test.y<<"\n";

    cin>>N;
    for(int i{}; i<N; i++) {
        double a,b;
        int d,g;
        cin>>a>>b>>d>>g;
        dragon_curve({a,-b},d,g,i);
        for(int j{}; j<dragon_curves[i].size(); j++) {
            auto cur = dragon_curves[0][i];
        }
    }

    for(int i{}; i<N; i++) {
        for(int j{}; j<dragon_curves[i].size(); j++) {
            auto cur = dragon_curves[i][j];
            map[(int)cur.x + 100][(int)cur.y + 100] = true;
        }
    }

    int ans = 0;
    for(int i{}; i<200; i++) {
        for(int j{}; j<200; j++) {
            if(!map[i][j])continue;
            if(!map[i+1][j])continue;
            if(!map[i][j+1])continue;
            if(!map[i+1][j+1])continue;
            ans++;
        }
    }

    // for(int i{}; i<N; i++) {
    //     print_dc(i);
    // }
    //print_map();
    cout<<ans;

    return 0;
}