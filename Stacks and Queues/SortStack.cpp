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
        void setElement(int val){
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
        Stack(){
            testa = NULL;
        }
        void push(int val){
            Nodo* nuovo = new Nodo(val);
            if(testa==NULL)
                testa = nuovo;
            else{
                nuovo->setSucc(testa);
                testa = nuovo;
            }
        }
        Nodo* pop(){
            if(testa){
                Nodo* tmp = testa;
                testa = testa->getSucc();
                return tmp;
                delete tmp;
            }
            return NULL;
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
        bool isEmpty(){
            return testa==NULL;
        }
        Nodo* getTesta(){
            if(testa)
                return testa;
            return NULL;
        }
};

void sort(Stack* s){
    Stack* r = new Stack();
    while(!s->isEmpty()){
        Nodo* tmp = s->pop();
        while(!r->isEmpty() && r->getTesta()->getElemento()>tmp->getElemento()){
            s->push(r->pop()->getElemento());
        }
        r->push(tmp->getElemento());
    }

    while(!r->isEmpty()){
        s->push(r->pop()->getElemento());
    }

    s->print();
}

int main(){
    Stack* s = new Stack();
    s->push(10);
    s->push(3);
    s->push(5);
    s->push(1);
    s->push(14);
    sort(s);
    return 0;
}