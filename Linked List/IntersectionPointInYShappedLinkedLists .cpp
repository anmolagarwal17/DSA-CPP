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

// Mine

int intersectPoint(Node* head1, Node* head2)
{
    if(head1 == NULL || head2 == NULL) return NULL;
    
    Node* c1 = head1;
    Node* c2 = head2;
    
    while(c1 != c2){
        c1 = (c1 == NULL) ? head2 : c1->next;
        c2 = (c2 == NULL) ? head1 : c2->next;
    }
    
    return c1->data;
}

// GFG's

// There are many methods to solve this problem.
// Method Using difference of node counts:

// Get count of the nodes in the first list, let be c1.
// Get count of the nodes in the second list, let be c2.
// Get the difference of counts d = abs(c1 – c2).
// Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes.
// Then we can traverse both the lists simultaneously till we come across a common node.

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    int n1=0, n2=0;
    Node* temp;
    
    //finding length of list1.
    for(temp = head1; temp; temp=temp->next)
        n1++;
        
    // finding length of list2.
    for(temp = head2; temp; temp=temp->next)
        n2++;
    
    //if list1 is longer, we ignore some of its starting
    //elements till it has as many elements as list2.
    for(  ; n1>n2 ; n1-- )
        head1 = head1->next;
        
    //similarly, if list2 is longer, we ignore some of its starting
    //elements till it has as many elements as list1.
    for(  ; n2>n1 ; n2-- )
        head2 = head2->next;
        
    //now we simply traverse ahead till we get the intersection point, if there 
    //is none, this loop will break when both pointers point at NULL.
    while( head1 != head2 )
    {
        head1 = head1->next;
        head2 = head2->next;
    }
    
    // if head1 is not NULL, we return its data otherwise we return -1.
    if(head1) 
    return head1->data;
    return -1;
}

int main() {
    cout << "Hello World!";
    return 0;
}