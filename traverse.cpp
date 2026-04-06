#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;
void display(){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"<=>";
        temp = temp->next;
    }
    cout<<"NULL";

}
int main (){
    head = new Node{10,NULL};
    head->next = new Node{20,NULL};
    head->next->next = new Node{30,NULL};
    head->next->next->next= new Node{40,NULL};
    head->next->next->next->next =new Node{50,NULL};
    display();

    return 0;
}
