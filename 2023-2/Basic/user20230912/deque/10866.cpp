#include <iostream>
#include <deque>
#include <string>



int main()
{
	std::deque<int> dq;

	int input_n, input_d;
	std::cin >> input_n;

	std::string input_s;

	for (int i = 0; i < input_n; i++) {
		std::cin >> input_s;

		if (input_s == "push_front") {
			std::cin >> input_d;
			dq.push_front(input_d);
			continue;
		}
		if (input_s == "push_back") {
			std::cin >> input_d;
			dq.push_back(input_d);
			continue;
		}
		if (input_s == "pop_front") {
			if (dq.empty() == 1) {
				std::cout << "-1" << '\n';
				continue;
			}
			else {
				std::cout << dq.front() << '\n';
				dq.pop_front();
				continue;
			}
		}
		if (input_s == "pop_back") {
			if (dq.empty() == 1) {
				std::cout << "-1" << '\n';
				continue;
			}
			else {
				std::cout << dq.back() << '\n';
				dq.pop_back();
				continue;
			}
		}
		if (input_s == "size") {
			std::cout << dq.size() << '\n';
			continue;
		}
		if (input_s == "empty") {
			if (dq.empty() == 1) {
				std::cout << "1" << '\n';
			}
			else
				std::cout << '0' << '\n';
			continue;
		}
		if (input_s == "front") {
			if (dq.empty()) {
				std::cout << "-1" << '\n';
				continue;
			}
			std::cout << dq.front() << '\n';
			continue;
		}
		if (input_s == "back") {
			if (dq.empty()) {
				std::cout << "-1" << '\n';
				continue;
			}
			std::cout << dq.back() << '\n';
			continue;
		}
	}	
}
