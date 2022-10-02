#include <iostream>
#include "linkedList.h"

using namespace std;

class Result{
    public:
        Node* tail;
        int size;

        Result(Node* tail, int size){
            this->tail = tail;
            this->size = size;
        }
};

Result* getTailAndSize(LinkedList* list){
    if(list->getHead()==NULL)
        return new Result(NULL, 0);

    int size = 1;

    Node* current = list->getHead();
    while(current->next != NULL){
        size++;
        current = current->next;
    }
    return new Result(current, size);
}

Node* getKthNode(Node* head, int k){
    Node* current = head;
    while(k>0 && current!=NULL){
        current = current->next;
        k--;
    }
    return current;
}

Node* findIntersection(LinkedList* list1, LinkedList* list2){
    if(list1->getHead()==NULL || list2->getHead()==NULL)
        return NULL;
    
    Result* result1 = getTailAndSize(list1);
    Result* result2 = getTailAndSize(list2);

    if(result1->tail != result2->tail)
        return NULL;

    Node* shorter = result1->size < result2->size ? list1->getHead() : list2->getHead();
    Node* longer = result1->size < result2->size ? list2->getHead() : list1->getHead();

    longer = getKthNode(longer, abs(result1->size - result2->size));

    while(shorter!=longer){
        shorter = shorter->next;
        longer = longer->next;
    }

    return longer;
}

int main(){
    LinkedList* list1 = new LinkedList();
    LinkedList* list2 = new LinkedList();
    Node* common = new Node(7);
    Node* node1 = new Node(2);
    Node* node2 = new Node(1);
    common->setNext(node1);
    node1->setNext(node2);
    list1->insert(3);
    list1->insert(1);
    list1->insert(5);
    list1->insert(9);
    list1->insertNode(common);
    list2->insert(4);
    list2->insert(6);
    list2->insertNode(common);
    cout << findIntersection(list1, list2)->data << endl;
    return 0;
}