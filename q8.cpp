#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

Node* funct(Node* head) {
    if (!head || !head->next) return head;
    Node* rest = funct(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if(head->next) cout << "->";
        head = head->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head = funct(head);
    printList(head); 
    return 0;
}
