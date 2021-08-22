// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/0/
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// my approach
struct Node* addTwoLists(struct Node* first, struct Node* second) {
    vector<int> f;
    vector<int> s;
    struct Node* ans = NULL;
    int carry = 0;

    struct Node* c1 = first;
    struct Node* c2 = second;

    while (c1 != NULL) {
        f.push_back(c1->data);
        c1 = c1->next;
    }

    while (c2 != NULL) {
        s.push_back(c2->data);
        c2 = c2->next;
    }

    int i1 = f.size() - 1, i2 = s.size() - 1;
    while (i1 >= 0 && i2 >= 0) {
        int current = f[i1] + s[i2] + carry;

        struct Node* newNode = new Node(current % 10);
        newNode->next = ans;
        ans = newNode;

        if (current > 9)
            carry = 1;
        else
            carry = 0;
        i1--;
        i2--;
    }

    while (i1 >= 0) {
        int current = f[i1] + carry;

        struct Node* newNode = new Node(current % 10);
        newNode->next = ans;
        ans = newNode;

        if (current > 9)
            carry = 1;
        else
            carry = 0;
        i1--;
    }

    while (i2 >= 0) {
        int current = s[i2] + carry;

        struct Node* newNode = new Node(current % 10);
        newNode->next = ans;
        ans = newNode;

        if (current > 9)
            carry = 1;
        else
            carry = 0;
        i2--;
    }

    if (carry) {
        struct Node* newNode = new Node(1);
        newNode->next = ans;
        ans = newNode;
    }

    return ans;
}

// GFG's

// Algorithm:

// Reverse both lists to simplify addition.
// Use a loop till both lists gets exhausted.
// Use a variable to store sum of two digits along with carry.
// Store sum of their data in newVal and update carry.
// Create new node which gets connected with other nodes that we get after calculating sum of respective digits.
// Store the previously made nodes in the link part of new node.
// Make the new node as the first node of all previously made node.
// Keep moving ahead in both lists.

//Function to reverse the linked list.
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

//Function to add two numbers represented by linked list.
struct Node* addTwoLists(struct Node* first, struct Node* second) {
    //reversing both lists to simplify addition.
    first = reverse(first);
    second = reverse(second);

    Node* sum = NULL;
    int carry = 0;

    //using a loop till both lists and carry gets exhausted.
    while (first != NULL || second != NULL || carry != 0) {
        //using a variable to store sum of two digits along with carry.
        int newVal = carry;

        //if nodes are left in any list, we add their data in newVal.
        if (first) newVal += first->data;
        if (second) newVal += second->data;

        //updating carry.
        carry = newVal / 10;

        //using modulus to store only a single digit at that place.
        newVal = newVal % 10;

        //creating new node which gets connected with other nodes that
        //we get after calculating sum of respective digits.
        Node* newNode = new Node(newVal);

        //storing the previously made nodes in the link part of new node.
        newNode->next = sum;

        //making the new node as the first node of all previously made node.
        sum = newNode;

        //moving ahead in both lists.
        if (first) first = first->next;
        if (second) second = second->next;
    }
    return sum;
}

int main() {
    cout << "Hello World!";
    return 0;
}