#include <iostream>
#include "linkedList.h"

using namespace std;

Node* addLists(Node* l1, Node* l2, int carry){
    if(l1==NULL && l2==NULL && carry==0)
        return NULL;
    Node* result = new Node();
    int value = carry;

    if(l1!=NULL)
        value+=l1->data;
    if(l2!=NULL)
        value+=l2->data;
    result->data = value % 10;

    if(l1!=NULL || l2!=NULL){
        Node* more = addLists(l1==NULL ? NULL : l1->next, l2==NULL ? NULL : l2->next, value>=10 ? 1 : 0);
        result->next = more;
    }
    return result;
}

int main(){
    LinkedList* list1 = new LinkedList();
    LinkedList* list2 = new LinkedList();
    list1->insert(7);
    list1->insert(1);
    list1->insert(6);
    list2->insert(5);
    list2->insert(9);
    list2->insert(2);
    Node* result = addLists(list1->getHead(), list2->getHead(), 0);

    while(result!=NULL){
        cout << result->data << endl;
        result = result->next;
    }

    return 0;
}