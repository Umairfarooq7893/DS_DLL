#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertBeg(int val) {
    Node* newNode = new Node{val, NULL, head};

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

void insertEnd(int val) {
    Node* newNode = new Node{val, NULL, NULL};

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertPos(int val, int pos) {
    if (pos == 1) {
        insertBeg(val);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Invalid Position\n";
        return;
    }

    Node* newNode = new Node{val, temp, temp->next};

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
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