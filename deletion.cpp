#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};
// Head pointer (start of the list)
Node* head = NULL;
// Delete node from beginning
void deleteBeg() {
    // If list is empty, nothing to delete
    if (head == NULL){
        return;
    }

    Node* temp = head;     // store current head
    head = head->next;     // move head to next node

    // If list is not empty, update new head's prev
    if (head != NULL)
        head->prev = NULL;

    delete temp;           // free memory of old head
}

void deleteEnd() {
    // If list is empty
    if (head == NULL) return;

    // If only one node exists
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    // Traverse to last node
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    // Remove last node by updating previous node
    temp->prev->next = NULL;

    delete temp;  // free memory
}

void deletePos(int pos) {
    // If position is 1, delete from beginning
    if (pos == 1) {
        deleteBeg();
        return;
    }

    // Traverse to the required position
    Node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    // If position is invalid
    if (temp == NULL) {
        cout << "Invalid Position\n";
        return;
    }

    // Update previous node's next pointer
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    // Update next node's prev pointer
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;  // free memory
}

void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL\n";  // end of list
}

int main() {
    head = new Node{10, NULL, NULL};
    head->next = new Node{20, head, NULL};
    head->next->next = new Node{30, head->next, NULL};
    head->next->next->next = new Node{40, head->next->next, NULL};

    deleteBeg(); 
    deleteEnd(); 
    deletePos(2); 
    
    display();
}

