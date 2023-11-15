#include <iostream>
#include <stack>

int board[10][10];

int v[10][10];

int input;

int max = 0;

int back(int x, int y, int number);

struct d3 {
    int x;
    int y;
    int del_x;
    int del_y;
};

std::stack<d3> s;

void search(int x, int y);

void s_back(int x, int y);

int main()
{
    int input2;

    std::cin >> input;

    for (int i = 0; i < input; i++) {
        for (int j = 0; j < input; j++) {
            v[i][j] = 1;
            std::cin >> input2;
            board[i][j] = input2;
        }
    }
    
    back(0, 0, 0);

    std::cout << max;
}

int back(int x, int y, int number) {

    for (int i = 0; i < input; i++) {
        for (int j = 0; j < input; j++) {
            if (board[i][j] == 1 && v[i][j] == 1) {
                v[i][j] = 0;
                number++;
                search(i, j);
                back(x, y, number);
                number--;
                s_back(i, j);
                back(x, y, number);
            }
            else continue;

        }
    }

    if (max < number)
        max = number;
    return 0;

}
void search(int x, int y) {

    int i = x + 1, j = y + 1;

    while (i < input && j < input) {
        if (board[i][j] == 1) {
            board[i][j] = 0;
            i++; j++;
            s.push({ x,y,i,j });
        }
        else
        {
            i++; j++;
        }
    }
    i = x - 1, j = y - 1;
    while (i > 0 && j > 0) {
        if (board[i][j] == 1) {
            board[i][j] = 0;
            i--; j--;
            s.push({ x,y,i,j });
        }
        else
        {
            i--; j--;
        }
    }
    i = x + 1, j = y - 1;
    while (i < input && j > 0) {
        if (board[i][j] == 1) {
            board[i][j] = 0;
            i++; j--;
            s.push({ x,y,i,j });
        }
        else
        {
            i++; j--;
        }
    }
    i = x - 1, j = y + 1;
    while (i > 0 && j < input) {
        if (board[i][j] == 1) {
            board[i][j] = 0;
            i--; j++;
            s.push({ x,y,i,j });
        }
        else
        {
            i--; j++;
        }
    }

}

void s_back(int x, int y) {
    if (!s.empty())
    {
        while (s.top().x == x && s.top().y == y) {
            board[s.top().del_x][s.top().del_y] = 1;
            s.pop();
            if (s.empty())
                break;
        }
 
    }
}
