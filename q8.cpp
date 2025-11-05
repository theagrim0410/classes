#include <iostream>
using namespace std;
// name : AGRIM SAXENA
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

Node* reverse(Node* head) {
    if (!head || !head->next)
        return head;
    Node* newhead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newhead;
}

void printList(Node* head) {
    while (head) {
        cout << head->data ;
        if (head->next) cout << "->";
        head = head->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << "Original : ";
    printList(head);
    cout << endl;
    head = reverse(head);
    cout << "Reversed : ";
    printList(head);
    return 0;
}
