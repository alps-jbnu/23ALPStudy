#define MAX 101
#include <iostream>
using namespace std;

string minimum[MAX], maximum[MAX];

void DP() {
    minimum[2] = "1";
    minimum[3] = "7";
    minimum[4] = "4";
    minimum[5] = "2";
    minimum[6] = "6";
    minimum[7] = "8";

    minimum[8] = "10";
    minimum[9] = "18";
    minimum[10] = "22";
    minimum[11] = "20";

    maximum[2] = "1";
    maximum[3] = "7";

    int firstIdx = 5;
    int secondIdx = 6;
    for(int i{4}; i<MAX; i++) {
        if(minimum[i].empty()) {
            if(firstIdx == 9 && secondIdx == 7) {
                firstIdx+=1;
                secondIdx-=1;
            }
            string firstVal = minimum[firstIdx+1];
            string secondVal = minimum[secondIdx];
            
            string first = firstVal.append(secondVal);
            
            firstVal = minimum[firstIdx];
            secondVal = minimum[secondIdx+1];

            string second = firstVal.append(secondVal);

            string third;
            third.append(minimum[i-6]);
            third.append("0");

            if(first.length() == second.length()) {
               if(stoi(first.substr(0, 2)) > stoi(second.substr(0, 2))) {
                    minimum[i] = second;
                    secondIdx+=1;
               }
               else {
                    minimum[i] = first;
                    firstIdx+=1;
               }
            }
            else {
                if(first.length() > second.length()) {
                    minimum[i] = second;
                    secondIdx+=1;
                }
                else {
                    minimum[i] = first;
                    firstIdx+=1;
                }
            }
        }
        maximum[i].append(maximum[i-2]);
        maximum[i].append(maximum[2]);
    }

    for(int i{2}; i<MAX; i++) {
        for(int j{1}; j<minimum[i].length(); j++) {
            if(minimum[i][j] == '6') minimum[i][j] = '0';
        }
    }
}

int T, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    DP();
    cin>>T;
    for(int i{}; i<T; i++) {
        cin>>n;
        // cout<<i<<": ";
        cout<<minimum[n]<<" "<<maximum[n]<<"\n";
    }

    return 0;
}