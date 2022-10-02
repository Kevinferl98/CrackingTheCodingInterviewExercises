#include <iostream>
#include "LinkedList.h"

using namespace std;

Node* LoopDetection(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
            break;
    }

    if(fast==NULL || fast->next==NULL)
        return NULL;
    
    slow = head;
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }

    return fast;
}

int main(){
    LinkedList* list = new LinkedList();
    Node* node1 = new Node(3);
    Node* node2 = new Node(5);
    node2->setNext(node1);
    list->insert(1);
    list->insert(2);
    list->insertNode(node1);
    list->insert(4);
    list->insertNode(node2);

    cout << LoopDetection(list->getHead())->data << endl; 
    return 0;
}
