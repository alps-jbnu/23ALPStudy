#include <bits/stdc++.h>

using namespace std;

int n, answer;
int effect[10][4][4];
char color[10][4][4];

int gama_effect[5][5];
char gama_color[5][5];
bool vst[10];

int rotate_effect(int i, int x, int y, int type) {
    if (type == 1) {
        return effect[i][3 - y][x];
    } else if (type == 2) {
        return effect[i][3 - x][3 - y];
    } else if (type == 3) {
        return effect[i][y][3 - x];
    }
    return effect[i][x][y];
}

char rotate_color(int i, int x, int y, int type) {
    if (type == 1) {
        return color[i][3 - y][x];
    } else if (type == 2) {
        return color[i][3 - x][3 - y];
    } else if (type == 3) {
        return color[i][y][3 - x];
    }
    return color[i][x][y];
}

void calculate_answer(int material_cnt, int R, int G, int B, int Y) {
    if (material_cnt == 3) {
        answer = max(answer, 7 * R + 5 * B + 3 * G + 2 * Y);
        return;
    }
    int gama_effect_old[5][5]; char gama_color_old[5][5];
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            gama_effect_old[x][y] = gama_effect[x][y];
            gama_color_old[x][y] = gama_color[x][y];
        }
    }
    for (int i = 0; i < n; i++) {
        if (vst[i]) continue;
        vst[i] = true;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int type = 0; type < 4; type++) {
                    int new_R = R, new_G = G, new_B = B, new_Y = Y;
                    for (int l = 0; l < 4; l++) {
                        for (int m = 0; m < 4; m++) {
                            if (gama_color[j + l][k + m] == 'R') {
                                new_R -= gama_effect[j + l][k + m];
                            } else if (gama_color[j + l][k + m] == 'G') {
                                new_G -= gama_effect[j + l][k + m];
                            } else if (gama_color[j + l][k + m] == 'B') {
                                new_B -= gama_effect[j + l][k + m];
                            } else if (gama_color[j + l][k + m] == 'Y') {
                                new_Y -= gama_effect[j + l][k + m];
                            }
                            gama_effect[j + l][k + m] += rotate_effect(i, l, m, type);
                            gama_effect[j + l][k + m] = max(gama_effect[j + l][k + m], 0);
                            gama_effect[j + l][k + m] = min(gama_effect[j + l][k + m], 9);
                            if (rotate_color(i, l, m, type) != 'W') {
                                gama_color[j + l][k + m] = rotate_color(i, l, m, type);
                            }
                            if (gama_color[j + l][k + m] == 'R') {
                                new_R += gama_effect[j + l][k + m];
                            } else if (gama_color[j + l][k + m] == 'G') {
                                new_G += gama_effect[j + l][k + m];
                            } else if (gama_color[j + l][k + m] == 'B') {
                                new_B += gama_effect[j + l][k + m];
                            } else if (gama_color[j + l][k + m] == 'Y') {
                                new_Y += gama_effect[j + l][k + m];
                            }
                        }
                    }
                    calculate_answer(material_cnt + 1, new_R, new_G, new_B, new_Y);
                    for (int x = 0; x < 5; x++) {
                        for (int y = 0; y < 5; y++) {
                            gama_effect[x][y] = gama_effect_old[x][y];
                            gama_color[x][y] = gama_color_old[x][y];
                        }
                    }
                }
            }
        }
        vst[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                cin >> effect[i][j][k];
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                cin >> color[i][j][k];
    }
    calculate_answer(0, 0, 0, 0, 0);
    cout << answer;
    return 0;
}
