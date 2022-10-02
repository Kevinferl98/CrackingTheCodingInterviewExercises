#include <iostream>
#include "linkedList.h"

using namespace std;

class NewLinkedList : public LinkedList{
    public:
        void DeleteMiddle(Node* tmp){
            tmp->data = tmp->next->data;
            tmp->next = tmp->next->next;
            cout << "Middle eliminato" << endl;
        }
};

int main(){
    NewLinkedList* list = new NewLinkedList();
    Node* a = new Node(1);
    Node* b = new Node(3);
    Node* c = new Node(1);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(3);
    list->insertNode(a);
    list->insertNode(b);
    list->insertNode(c);
    list->insertNode(d);
    list->insertNode(e);
    list->insertNode(f);
    list->print();
    list->DeleteMiddle(c);
    list->print();
    return 0;
}