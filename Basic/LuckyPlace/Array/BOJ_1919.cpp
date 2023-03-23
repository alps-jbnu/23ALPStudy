#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int ch1[256] = { 0 };
    int ch2[256] = { 0 };
    string str1, str2;
    cin >> str1 >> str2;
    
    for (int i = 0; i < str1.size(); i++)
        ch1[str1[i]]++;

    for (int i = 0; i < str2.size(); i++)
        ch2[str2[i]]++;

    int total = 0;
    for (int i = 0; i < 256; i++)
    {
        if (ch1[i] == ch2[i])
            continue;
        else if (ch1[i] > ch2[i])
            total += ch1[i] - ch2[i];
        else if (ch1[i] < ch2[i])
            total += ch2[i] - ch1[i];
    }
    cout << total << endl;

    return 0;
}