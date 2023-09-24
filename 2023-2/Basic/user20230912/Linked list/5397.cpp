#include <iostream>
#include <list>

int main()
{
    int input;
    
    std::cin >> input;

    while (input--) {
        
        std::list<char> l;

        std::string s;

        std::cin >> s;

        std::list<char>::iterator iter = l.begin();

        for (int i = 0; i < s.size(); i++) {





            if (s.at(i) == '<') {
                if (iter != l.begin()) {
                    iter--;
                }
            }

            else if (s.at(i) == '>') {
                if (iter != l.end()) {
                    iter++;
                }
            }

            else if (s.at(i) == '-') {
                if (iter != l.begin()) {
                    iter--;
                    iter = l.erase(iter);
                }
            }

            else {
                //iter--;
                l.insert(iter, s.at(i));
            }

        }

        for (auto& i : l) {
            std::cout << i;
        }
        std::cout << '\n';

    }
}
