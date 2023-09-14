#include <iostream>
#include <string>

using namespace std;

string *stack;

int ind = -1;

void push(string d) {
    ind = ind + 1;
    stack[ind] = d;
}

void pop() {
    if (ind == -1) {
        cout << "-1" << endl;
    }
    else {
        string e = stack[ind];
        ind = ind - 1;
        cout << e << endl;
    }
}

void top() {
    if (ind == -1) {
        cout << "-1" << endl;
    }
    else {
        cout << stack[ind] << endl;
    }
}

void size() {
    cout << ind + 1 << endl;
}

void empty() {
    if (ind == -1) {
        cout << "1" << endl;
    }
    else {
        cout << "0" << endl;
    }
}

int main() {
    int a;
    cin >> a;
    stack = new string[a]; 
    for (int i = 0; i < a; i++) {
        string b;
        cin >> b;
        if (b == "push") {
            string d;
            cin >> d;
            push(d);
        }
        else if (b == "pop") {
            pop();
        }
        else if (b == "top") {
            top();
        }
        else if (b == "size") {
            size();
        }
        else if (b == "empty") {
            empty();
        }
    }
    delete[] stack; 
}
