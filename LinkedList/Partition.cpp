#include <iostream>
#include "linkedList.h"

using namespace std;

class NewLinkeList : public LinkedList{
    public:
        LinkedList* partition(int value){
            LinkedList* list = new LinkedList();
            Node* tmp = this->getHead();
            while(tmp!=NULL){
                if(tmp->data<value)
                    list->insert(tmp->data);
                tmp = tmp->next;
            }
            tmp = this->getHead();
            while(tmp!=NULL){
                if(tmp->data>=value)
                    list->insert(tmp->data);
                tmp = tmp->next;
            }
            return list;
        }
};

int main(){
    NewLinkeList* list = new NewLinkeList();
    list->insert(3);
    list->insert(5);
    list->insert(8);
    list->insert(5);
    list->insert(10);
    list->insert(2);
    list->insert(1);
    list->print();
    LinkedList* newList = list->partition(5);
    newList->print();
}