#include <iostream>
using namespace std;
// name : AGRIM SAXENA
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

Node* func(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    if (a->data < b->data) {
        a->next = func(a->next, b);
        return a;
    } 
    else {
        b->next = func(a, b->next);
        return b;
    }
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* a = new Node(1);
    a->next = new Node(3);
    a->next->next = new Node(5);

    Node* b = new Node(2);
    b->next = new Node(4);
    b->next->next = new Node(6);

    Node* merged = func(a, b);
    cout << endl;
    printList(merged);
    return 0;
}
