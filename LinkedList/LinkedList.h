#ifndef linkedList
#define linkedList

using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(){}

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

        void setHead(Node* x){
            head = x;
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

        void insertNode(Node* tmp){
            if(head==NULL)
                head = tmp;
            else{
                Node* last = head;
                while(last->next!=NULL)
                    last = last->next;
                last->next = tmp;
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

#endif
