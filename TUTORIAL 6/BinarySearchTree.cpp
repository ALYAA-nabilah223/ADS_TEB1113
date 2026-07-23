#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    void insert(int val) {
        if (val < data) {
            if (left == NULL) {
                left = new Node(val);
            } else {
                left->insert(val);
            }
        } else if (val > data) {
            if (right == NULL) {
                right = new Node(val);
            } else {
                right->insert(val);
            }
        }
    }

    bool search(int val) {
        if (val == data) {
            return true;
        }
        if (val < data) {
            return left != NULL && left->search(val);
        } else {
            return right != NULL && right->search(val);
        }
    }

    void displayInOrder() {
        if (left != NULL) {
            left->displayInOrder();
        }
        cout << data << " ";
        if (right != NULL) {
            right->displayInOrder();
        }
    }
};

int main() {
    Node* root = new Node(50);

    root->insert(30);
    root->insert(20);
    root->insert(40);
    root->insert(70);
    root->insert(60);
    root->insert(80);

    cout << "In-order traversal: ";
    root->displayInOrder();
    cout << endl;

    cout << "Search 40: " << (root->search(40) ? "found" : "not found") << endl;
    cout << "Search 90: " << (root->search(90) ? "found" : "not found") << endl;

    return 0;
}