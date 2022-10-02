#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            next = NULL;
        }
};

class LinkedList{
    private: 
        Node* head;
    public:

        LinkedList(){
            head = NULL;
        }

        Node* getHead(){
            return head;
        }

        void insert(int value){
            Node* newNode = new Node(value);

            if(head==NULL)
                head = newNode;
            else{
                Node* last = head;
                while(last->next!=NULL){
                    last = last->next;
                }
                last->next = newNode;
            }
        }

        int KthToLast(Node* tmp, int k){
            if(tmp==NULL){
                cout << "Ritorno 0" << endl;
                return 0;
            }
            int index = KthToLast(tmp->next, k) + 1;
            cout << "Il mio valore di index e: " << index << endl;
            if(index==k)
                cout << k << "th to last node is " << tmp->data << endl;
            return index;
        } 

        void print(){
            Node* curr = head;

            while(curr!=NULL){
                cout << curr->data << " ";
                curr = curr->next;
            }
            cout << endl;
        }
};


int main(){
    LinkedList* list = new LinkedList();
    list->insert(1);
    list->insert(3);
    list->insert(1);
    list->insert(4);
    list->insert(5);
    list->insert(3);
    Node* tmp = list->getHead();
    list->KthToLast(tmp, 2);
    return 0;
}