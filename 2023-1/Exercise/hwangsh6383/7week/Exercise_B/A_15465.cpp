#include <bits/stdc++.h>

using namespace std;

int getHighesetIndex(int output[]) {
    if(output[0] < output[1])
    {
        if(output[1] < output[2])
        {
            return 2;
        }
        else if(output[1] > output[2])
        {
            return 1;
        }
        else
        {
            return 12;
        }
    }
    else if(output[0] > output[1])
    {
        if(output[0] < output[2])
        {
            return 2;
        }
        else if(output[0] > output[2])
        {
            return 0;
        }
        else
        {
            return 20;
        }
    }
    else
    {
        if(output[1] == output[2])
        {
            return 120;
        }
        else
        {
            if(output[1] < output[2])
            {
                return 2;
            }
            else
            {
                return 10;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<pair<int,pair<string,int>>> v;
    for(int i = 0; i < N; i++)
    {
        int day, milk; string name;
        cin >> day >> name >> milk;
        v.push_back(make_pair(day,make_pair(name, milk)));
    }
    sort(v.begin(), v.end());

    int index = -1; // 0 1 2 10 20 12 120
    int output[3] = {7,7,7};
    int answer = 0;
    for(auto cur : v)
    {
        if(cur.second.first == "Mildred")
        {
            output[0] += cur.second.second;
            int hindex = getHighesetIndex(output);
            if(index != hindex)
            {
                answer++;
                index = hindex;
            }
        }
        else if(cur.second.first == "Elsie")
        {
            output[1] += cur.second.second;
            int hindex = getHighesetIndex(output);
            if(index != hindex)
            {
                answer++;
                index = hindex;
            }
        }
        else
        {
            output[2] += cur.second.second;
            int hindex = getHighesetIndex(output);
            if(index != hindex)
            {
                answer++;
                index = hindex;
            }
        }
    }
    cout << answer;
    return 0;
}
