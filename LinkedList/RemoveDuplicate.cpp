#include <iostream>
#include <unordered_set>

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

        void removeDuplicate(){
            Node* temp = head;
            Node* prev = NULL;
            Node* temp2 = NULL;

            while(temp!=NULL){
                int val = temp->data;
                prev = temp;
                temp2 = temp->next;
                while(temp2!=NULL){
                    if(temp2->data==val)
                        prev->next = temp2->next;
                    prev = prev->next;
                    temp2 = temp2->next;
                }
                temp = temp->next;
            }
            cout << "Valori duplicati rimossi" << endl;
        }

        void removeDuplicateBook(){
            unordered_set <int> set;
            Node* temp = head;
            Node* prev = NULL;

            while(temp!=NULL){
                if(set.find(temp->data) != set.end())
                    prev->next = temp->next;
                else{
                    set.insert(temp->data);
                    prev = temp;
                }
                //prev = prev->next;
                temp = temp->next;
            }
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
    list->print();
    //list->removeDuplicate();
    list->removeDuplicateBook();
    list->print();
    delete list;
    return 0;
}