#include <iostream>
#include <vector>

using namespace std;

bool stack_empty(vector<int>& stack) {
    if (stack.size() == 0) {
        return true;
    }
    else {
        return false;
    }
}

void push(vector<int>& stack, int& x) {
    stack.push_back(x);
}

void pop(vector<int>& stack) {
    if (stack_empty(stack)) {
        cout << "niedomiar" << "\n";
    } else {
        stack.pop_back();
    }
}

int main() {
    vector<int> stack = {1, 2, 3};
    int x = 5;

    push(stack, x);

    for (int i=0; i<stack.size(); i++) {
        cout << stack[i] << " ";
    }

    cout << "\n";

    pop(stack);

    for (int i=0; i<stack.size(); i++) {
        cout << stack[i] << " ";
    }

    return 0;
}
