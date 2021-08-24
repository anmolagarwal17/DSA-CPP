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

// my code(have memory leak problem)
// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node* head)
{
    if(head == NULL) return head;
    
    int total = 0;
    Node* current = head;
    
    while(current != NULL){
        total++;
        current = current->next;
    }
    if(total == 1) return NULL;
    
    current = head;
    int i = 1;
    while(i < total/2){
        current = current->next;
        i++;
    }
    
    current->next = current->next->next;
    
    return head;
}

// GFG's

struct Node *deleteMid(struct Node *head)
{
    if (head == NULL) return NULL;
    
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    
    struct Node *prev = NULL;
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;
    
    
    while (fast_ptr != NULL && fast_ptr->next != NULL) 
    {
        fast_ptr = fast_ptr->next->next;
        // fast pointer moves 2 nodes ahead everytime loop is run 
        
        prev = slow_ptr;
        // updating prev, prev holds previous value of slow pointer
        
        slow_ptr = slow_ptr->next;
        // slow pointer moves 1 node ahead everytime loop is run
    }
    
    // since slow pointer was moving at half speed, it points at
    // mid node when fast pointer reaches the end
    prev->next = slow_ptr->next; // bypassing mid node
    delete slow_ptr;
    
    return head;
}

int main() {
    cout << "Hello World!";
    return 0;
}