#include<iostream>
using namespace std;

// Declaring Node
struct Node{
    Node* previous;
    int data;
    Node* next;
};

int main(){
    // Create nodes
    // always 
    Node* first  = new Node();
    Node* second = new Node();
    Node* third  = new Node();
    Node* last   = new Node();

    // Link nodes
    first->previous = NULL;
    first->data     = 10;
    first->next     = second;

    second->previous = first;
    second->data     = 20;
    second->next     = third;

    third->previous = second;
    third->data     = 30;
    third->next     = last;

    last->previous = third;
    last->data     = 40;
    last->next     = NULL;

    // Print Forward
    Node* temp = first;
    cout<<"Forward: NULL -> ";
    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL\n\n";

    // Print Backward
    Node* back = last;
    cout<<"Backward: NULL <- ";
    while(back != NULL){
        cout<<back->data<<" <- ";
        back = back->previous;
    }
    cout<<"NULL\n";
}

