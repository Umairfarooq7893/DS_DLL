#include<iostream>
using namespace std;
// Node structure
struct Node{
    Node* previous;
    int data;
    Node* next;
};
int main(){
    Node* first = new Node{NULL, 10, NULL};
    first->next = new Node{first, 20, NULL};
    first->next->next = new Node{first->next, 30, NULL};
    first->next->next->next = new Node{first->next->next, 40, NULL};

    // Define last node
    Node* last = first->next->next->next;

    // Forward Traversal
    Node* temp = first;
    cout << "Forward Traversal: ";
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    // Backward Traversal
    temp = last;
    cout << "\nBackward Traversal: ";
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->previous;
    }
    return 0;
}

