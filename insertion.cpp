#include <iostream>
using namespace std;

struct Node {
    int data; 
    Node* prev;
    Node* next;
};

// Head pointer (starting point of the list)
Node* head = NULL;

void insertBeg(int value) {
    // Create a new node
    Node* newNode = new Node();

    newNode->prev = NULL;   // Since it will be first node, prev is NULL
    newNode->data = value;
    newNode->next = head;   // Point to current head

    // If list is not empty, update previous head's prev pointer
    if (head != NULL)
        head->prev = newNode;

    // Move head to new node
    head = newNode;
}

void insertEnd(int value) {
    // Create a new node
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;  // Last node always points to NULL

    // If list is empty, make new node as head
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Traverse to the last node
    Node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }

    // Link the last node with new node
    temp->next = newNode;
    newNode->prev = temp;
}

void insertPos(int value, int pos) {
    // If position is 1, insert at beginning
    if (pos == 1) {
        insertBeg(value);
        return;
    }
    // Traverse to (pos-1)th node
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }

    // If position is invalid (beyond list length)
    if (temp == NULL) {
        cout << "Invalid Position\n";
        return;
    }

    // Create new node
    Node* newNode = new Node();
    newNode->prev = temp;
    newNode->data = value;

    // Adjust next pointers
    newNode->next = temp->next;

    // If not inserting at end, fix next node's prev pointer
    if (temp->next != NULL)
        temp->next->prev = newNode;

    // Link previous node to new node
    temp->next = newNode;
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <=> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main() {
    insertBeg(10);
    insertBeg(5);
    insertEnd(20);
    insertPos(15, 3);

    display();
}