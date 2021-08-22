// https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/0/
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void display(Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
}

// recursive solution
Node* pairWiseSwap(struct Node* head) {
    if (head == NULL || head->next == NULL) return head;
    struct Node* current = head;
    struct Node* next;

    next = current->next;
    current->next = pairWiseSwap(next->next);
    next->next = current;

    return next;
}

// iterative solution
Node* pairWiseSwap(Node* head) {
    Node *a = head, *b, *c;
    Node* prev = NULL;

    while (a && a->next) {
        b = a->next;  // b is second node
        c = b->next;  // c is third node (c might be null)
                      // current order : prev - a - b - c

        if (a == head)
            // b will be new head
            head = b;
        else
            // else, linking second node i.e. b, to a's ancestor
            prev->next = b;

        b->next = a;  // a should now come after b
        a->next = c;  // connecting a to list ahead

        // now we have to update a and prev for next pair
        prev = a;
        a = c;
    }

    return head;
}

int main() {
    cout << "Hello World!";
    return 0;
}