#include <bits/stdc++.h>

using namespace std;

vector<int> alist, blist, ans;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, i, tmp;

    cin >> a >> b;

    for(i = 0; i < a; i++)
    {
        cin >> tmp;
        alist.push_back(tmp);
    }

    for(i = 0; i < b; i++)
    {
        cin >> tmp;
        blist.push_back(tmp);
    }

    sort(alist.begin(), alist.end());
    sort(blist.begin(), blist.end());

    int idxA = 0, idxB = 0;

    while(idxA < alist.size() && idxB < blist.size())
    {
        if(alist[idxA] == blist[idxB])
        {
            idxA++;
            idxB++;
        }
        else if(alist[idxA] < blist[idxB])
        {
            ans.push_back(alist[idxA]);
            idxA++;
        }
        else
        {
            idxB++;
        }
    }

    while(idxA < alist.size())
    {
        ans.push_back(alist[idxA]);
        idxA++;
    }

    cout << ans.size() << "\n";

    for(i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
