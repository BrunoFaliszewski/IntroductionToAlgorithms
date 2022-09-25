#include <iostream>
#include <vector>

using namespace std;

void enqueue(vector<int>& queue, int length, int& tail, int x) {
    queue[tail] = x;
    if (tail == length-1) {
        tail = 0;
    } else {
        tail++;
    }
}

int dequeue(vector<int>& queue, int length, int& head) {
    int x = queue[head];
    if (head == length-1) {
        head = 0;
    } else {
        head++;
    }
    return x;
}

int main () {
    vector<int> queue = {0, 0, 0, 0, 0, 0, 15, 6, 9, 8, 4, 0};
    int length = 12;

    int head = 6;
    int tail = 11;

    for (int i=0; i<queue.size(); i++) {
        cout << queue[i] << " ";
    }

    cout << "\n";

    enqueue(queue, length, tail, 17);
    enqueue(queue, length, tail, 3);
    enqueue(queue, length, tail, 5);

    for (int i=0; i<queue.size(); i++) {
        cout << queue[i] << " ";
    }

    cout << "\n";

    cout << dequeue(queue, length, head) << "\n";

    for (int i=0; i<queue.size(); i++) {
        cout << queue[i] << " ";
    }

    return 0;
}