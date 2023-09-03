#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    for (int j = 0; j < N; j++)
    {
        int ch[256] = { 0 };
        string str1, str2;
        cin >> str1 >> str2;

        for (int i = 0; i < str1.size(); i++)
            ch[str1[i]]++;

        for (int i = 0; i < str2.size(); i++)
            ch[str2[i]]--;

        bool is_pos = true;

        for (int i = 0; i < 256; i++)
            if (ch[i] != 0)
                is_pos = false;

        if (is_pos)
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;
    }

    return 0;
}