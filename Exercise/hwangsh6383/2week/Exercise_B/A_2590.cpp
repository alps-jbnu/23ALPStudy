#include <bits/stdc++.h>

using namespace std;

int paper[7];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 1; i <= 6; i++)
    {
        cin >> paper[i];
    }
    int answer = paper[6] + paper[5] + paper[4];
    paper[1] -= 11 * paper[5]; // 5 * 5
    if(paper[4] > paper[2] / 5) // 4 * 4
    {
        int tp = paper[4] - paper[2] / 5;
        if(paper[1] > 0)
            paper[1] -= (5 - (paper[2] % 5)) * 4 + (tp - 1) * 20;
        paper[2] = 0;
    }
    else
    {
        paper[2] -= paper[4] * 5;
    }
    int temp = paper[3] / 4; // 3 * 3
    answer += temp + 1;
    temp = paper[3] % 4;
    if(temp == 3)
    {
        if(paper[2] >= 1)
        {
            paper[2] -= 1;
            if(paper[1] > 0)
                paper[1] -= 5;
        }
        else
        {
            if(paper[1] > 0)
                paper[1] -= 9;
        }
    }
    else if(temp == 2)
    {
        if(paper[2] >= 3)
        {
            paper[2] -= 3;
            if(paper[1] > 0)
                paper[1] -= 6;
        }
        else if(paper[2] == 2)
        {
            paper[2] -= 2;
            if(paper[1] > 0)
                paper[1] -= 10;
        }
        else if(paper[2] == 1)
        {
            paper[2] -= 1;
            if(paper[1] > 0)
                paper[1] -= 14;
        }
        else
        {
            if(paper[1] > 0)
                paper[1] -= 18;
        }
    }
    else if(temp == 1)
    {
        if(paper[2] >= 5)
        {
            paper[2] -= 5;
            if(paper[1] > 0)
                paper[1] -= 7;
        }
        else if(paper[2] == 4)
        {
            paper[2] -= 4;
            if(paper[1] > 0)
                paper[1] -= 11;
        }
        else if(paper[2] == 3)
        {
            paper[2] -= 3;
            if(paper[1] > 0)
                paper[1] -= 15;
        }
        else if(paper[2] == 2)
        {
            paper[2] -= 2;
            if(paper[1] > 0)
                paper[1] -= 19;
        }
        else if(paper[2] == 1)
        {
            paper[2] -= 1;
            if(paper[1] > 0)
                paper[1] -= 23;
        }
        else
        {
            if(paper[1] >= 0)
                paper[1] -= 27;
        }
    }
    else
        answer--;
    if(paper[2] > 0) // 2 * 2
    {
        temp = paper[2] / 9;
        answer += temp + 1;
        temp = paper[2] % 9;
        if(temp == 0)
            answer--;
        else
            if(paper[1] > 0)
                paper[1] -= (9 - temp) * 4;
    }
    if(paper[1] > 0) // 1 * 1
    {
        temp = paper[1] / 36;
        answer += temp;
        temp = paper[1] % 36;
        if(temp > 0)
        {
            answer++;
        }
    }
    cout << answer;
    return 0;
}
