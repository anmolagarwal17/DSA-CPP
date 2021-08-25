#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node* next;

    node(int x) {
        data = x;
        next = NULL;
    }
} * head;

// my code
struct node* reverse(struct node* head, int k) {
    if (head == NULL) return head;
    node* prev = NULL;
    node* current = head;
    node* next = NULL;

    int i = 0;
    while (i < k && current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        i++;
    }
    head->next = reverse(current, k);

    return prev;
}

// almost similar GFG's code
struct node* reverse(struct node* head, int k) {
    struct node* current = head;
    struct node* next = NULL;
    struct node* prev = NULL;
    int count = 0;

    while (current != NULL && count < k)
    // reversing k elements :
    {
        next = current->next;  // marking next node
        current->next = prev;  // reversing link
        prev = current;        // updating prev
        current = next;        // updating current
        count++;
    }

    if (next != NULL)                   // checking if there are nodes ahead
        head->next = reverse(next, k);  // reversing those recursively

    return prev;  // returning new head
}

int main() {
    cout << "Hello World!";
    return 0;
}