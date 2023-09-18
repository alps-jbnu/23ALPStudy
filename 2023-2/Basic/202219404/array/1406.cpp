#include <iostream>
#include <list>

int main()
{
    std::list<char> l;
    std::string s;

    std::cin >> s;

    for (int i = 0; i < s.size(); i++) {
        l.push_back(s.at(i));
    }

    int input;
    char d;
    std::list<char>::iterator iter = l.end();

    std::cin >> input;

    for (int i = 0; i < input; i++) {
        std::cin >> d;
        if (d == 'L') {
            if (iter != l.begin()) {
                iter--;
            }

        }
        if (d == 'D') {
            if (iter != l.end()) {
                iter++;
            }

        }

        if (d == 'B') {
            if (iter != l.begin()) {
                iter--;
                iter = l.erase(iter);
            }
        }

        if (d == 'P') {
            std::cin >> d;
            //iter--;
            l.insert(iter,d);
        }

    }
    for (auto& i:l) {
        std::cout << i;
    }

}
