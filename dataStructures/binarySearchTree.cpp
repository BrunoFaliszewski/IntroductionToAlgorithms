#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* parent;
    Node* left;
    Node* right;
};

class BinarySearchTree {
    private:
        Node* root = NULL;
    public:
        Node* getRoot();
        void inorderTreeWalk(Node* x);
        void insert(int value);
        Node* search(Node* x, int k);
        Node* minimum(Node* x);
        Node* maximum(Node* x);
        Node* successor(Node* x);
        Node* predecessor(Node* x);
        void transplant(Node* u, Node* v); // transplant sub-tree "u" by sub-tree "v"
        void treeDelete(Node* x);
};

Node* BinarySearchTree::getRoot() {
    return root;
}

void BinarySearchTree::inorderTreeWalk(Node* x) {
    if (x != NULL) {
        inorderTreeWalk(x->left);
        cout << x->value << " ";
        inorderTreeWalk(x->right);
    }
}

void BinarySearchTree::insert(int value) {
    Node* x = root;
    Node* y = NULL;
    Node* z = new Node();
    z->value = value;
    while (x != NULL) {
        y = x;
        if (z->value < x->value) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == NULL) {
        root = z;
    } else if (z->value < y->value) {
        y->left = z;
    } else {
        y->right = z;
    }
}

Node* BinarySearchTree::search(Node* x, int k) {
    while (x != NULL && k != x->value) {
        if (k < x->value) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return x;
}

Node* BinarySearchTree::minimum(Node* x) {
    while (x->left != NULL) {
        x = x->left;
    }
    return x;
}

Node* BinarySearchTree::maximum(Node* x) {
    while (x->right != NULL) {
        x = x->right;
    }
    return x;
}

Node* BinarySearchTree::successor(Node* x) {
    if (x->right != NULL) {
        return minimum(x->right);
    }
    Node* y = x->parent;
    while (y != NULL && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

Node* BinarySearchTree::predecessor(Node* x) {
    if (x->left != NULL) {
        return maximum(x->left);
    }
    Node* y = x->parent;
    while (y != NULL && x == y->left) {
        x = y;
        y = y->parent;
    }
    return y;
}

void BinarySearchTree::transplant(Node* u, Node* v) {
    if (u->parent == NULL) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != NULL) {
        v->parent = u->parent;
    }
    return;
}

void BinarySearchTree::treeDelete(Node* x) {
    if (x->left == NULL) {
        transplant(x, x->right);
    } else if (x->right == NULL) {
        transplant(x, x->left);
    } else {
        Node* y = minimum(x->right);
        if (y->parent != x) {
            transplant(y, y->right);
            y->right = x->right;
            y->right->parent = y;
        }
        transplant(x, y);
        y->left = x->left;
        y->left->parent = y;
    }
}

int main() {
    BinarySearchTree BST;

    BST.insert(4);
    BST.insert(3);
    BST.insert(5);
    BST.insert(7);

    BST.inorderTreeWalk(BST.getRoot());
    cout << "\n";

    BST.insert(6);

    BST.inorderTreeWalk(BST.getRoot());
    cout << "\n";

    cout << BST.minimum(BST.getRoot())->value << "\n";
    cout << BST.predecessor(BST.search(BST.getRoot(), 5))->value << "\n";
    cout << BST.successor(BST.search(BST.getRoot(), 5))->value << "\n";
    cout << BST.maximum(BST.getRoot())->value << "\n";

    BST.treeDelete(BST.search(BST.getRoot(), 4));
    BST.inorderTreeWalk(BST.getRoot());
    cout << "\n";

    return 0;
}