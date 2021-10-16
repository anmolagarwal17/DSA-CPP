// https://www.softwaretestinghelp.com/linked-list/
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

void display(Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
}

struct Node *reverseList(struct Node *head) {
    if (head == NULL)
        return NULL;

    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// extra functions

int count(struct Node *head, int search_for) {
    struct Node *current = head;
    int counter = 0;
    while (current != NULL) {
        if (current->data == search_for) counter++;
        current = current->next;
    }
    return counter;
}

// todo: implement all other linked list functions

int main() {
    cout << "Hello World!";
    return 0;
}