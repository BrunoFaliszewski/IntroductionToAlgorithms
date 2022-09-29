#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void push_front(Node*& head, Node*& sentinel, int x) {
    Node* node = new Node();
    node->data = x;

    if (sentinel->prev == sentinel) {
        node->prev = sentinel;
        node->next = sentinel;
        sentinel->prev = node;
        sentinel->next = node;
        head = node;
    } else {
        node->next = sentinel->next;
        node->prev = sentinel;
        sentinel->next->prev = node;
        sentinel->next = node;
        head = node;
    }
}

auto search(Node*& sentinal, int x) {
    Node* i = sentinal->next;

    while (i != sentinal && i->data!=x) {
        i = i->next;
    }
    return i;
}

void delete_node(Node*& x, Node*& head) {
    x->prev->next = x->next;
    x->next->prev = x->prev;
}

void displayList(Node* node, Node*& sentinel) {
   Node* last;
  
   while (node != sentinel) {
      cout<<node->data<<"<==>";
      last = node;
      node = node->next;
   }
   if(node == sentinel) {
    cout<<"NULL";
   }
   cout << "\n";
}

int main() {
    Node* sentinel = new Node();
    sentinel->prev = sentinel;
    sentinel->next = sentinel;
    Node* head = sentinel;

    displayList(head, sentinel);

    push_front(head, sentinel, 5);
    push_front(head, sentinel, 4);
    push_front(head, sentinel, 7);
    push_front(head, sentinel, 3);
    push_front(head, sentinel, 8);
    push_front(head, sentinel, 9);

    displayList(head, sentinel);

    Node* x = search(head, 4);

    delete_node(x, head);

    displayList(head, sentinel);

    return 0;
}