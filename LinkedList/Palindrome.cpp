#include <iostream>
#include "linkedListChar.h"

using namespace std;

Node* reverse(LinkedList* list){
    Node* current = list->getHead();
    Node* prev = NULL;
    Node* next = NULL;

    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev; 
}

bool palindrome(Node* list1, Node* list2){
    if(list1==NULL || list2==NULL)
        return false;
    while(list1!=NULL && list2!=NULL){
        if(list1->data!=list2->data)
            return false;
        list1 = list1->next;
        list2 = list2->next;
    }
    return true;
}

int main(){
    LinkedList* list1 = new LinkedList();
    list1->insert('a');
    list1->insert('n');
    list1->insert('n');
    list1->insert('a');
    Node* list2 = reverse(list1);
    cout << palindrome(list1->getHead(), list2) << endl;
    return 0;
}