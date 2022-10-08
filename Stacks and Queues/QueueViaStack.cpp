#include <iostream>

using namespace std;

class Nodo{
    private:
        int elemento;
        Nodo* succ;
    public:
        Nodo(int val){
            elemento = val;
            succ = NULL;
        }  
        int getElemento(){
            return elemento;
        }
        Nodo* getSucc(){
            return succ;
        }
        void setElemento(int val){
            elemento = val;
        }
        void setSucc(Nodo* x){
            succ = x;
        }
};

class Stack{
    private:
        Nodo* testa;
    public:
        int size;
        Stack(){
            testa = NULL;
            size = 0;
        }
        void push(int val){
            Nodo* nuovo = new Nodo(val);
            if(testa==NULL)
                testa = nuovo;
            else{
                nuovo->setSucc(testa);
                testa = nuovo;
            }
            size++;
        }
        Nodo* pop(){
            if(testa){
                Nodo* tmp = testa;
                testa = testa->getSucc();
                size--;
                return tmp;
                delete tmp;
            }
            else{
                return NULL;
            }
        }
        Nodo* getTesta(){
            return testa;
        }
        void print(){
            if(testa){
                Nodo* iter = testa;
                while(iter!=NULL){
                    cout << iter->getElemento() << " ";
                    iter = iter->getSucc();
                }
                cout << endl;
            }
        }
};

class Queue{
    private:
        Stack* s1;
        Stack* s2;
    public:
        Queue(){
            s1 = new Stack();
            s2 = new Stack();
        }
        void insert(int val){
            s1->push(val);
        }
        void remove(){
            while(s1->size>1){
                s2->push(s1->pop()->getElemento());
            }
            s1->pop();
            while(s2->size>0){
                s1->push(s2->pop()->getElemento());
            }
        }
        void print(){
            s1->print();
        }
};

int main(){
    Queue* queue = new Queue();
    queue->insert(1);
    queue->print();
    queue->insert(2);
    queue->print();
    queue->insert(3);
    queue->print();
    queue->insert(4);
    queue->print();
    queue->insert(5);
    queue->print();
    queue->insert(6);
    queue->print();
    queue->remove();
    queue->print();
    queue->remove();
    queue->print();
    return 0;
}