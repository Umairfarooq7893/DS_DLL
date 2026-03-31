#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void create(int val) {
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

void search(int key) {
    Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Found at position: " << pos;
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Not Found";
}

int main() {
    create(10);
    create(20);
    create(30);

    search(20);
}