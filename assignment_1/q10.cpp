#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* func(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->data < l2->data) {
        l1->next = func(l1->next, l2);
        return l1;
    } else {
        l2->next = func(l1, l2->next);
        return l2;
    }
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
}

Node* create(int arr[], int n) {
    if (n == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};

    Node* l1 = create(arr1, 4);
    Node* l2 = create(arr2, 4);

    Node* merged = func(l1, l2);
    printList(merged);
    return 0;
}
