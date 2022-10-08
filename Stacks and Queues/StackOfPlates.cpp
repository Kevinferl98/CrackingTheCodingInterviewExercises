#include <iostream>
#include <vector>

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
        void setSucc(Nodo* succ){
            this->succ = succ;
        }
};

class Stack{
    private:
        Nodo* testa;
        int max;
    public:
        int size;
        Stack(){
            testa = NULL;
            max = 4;
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
        void pop(){
            if(testa){
                Nodo* tmp=testa;
                testa=testa->getSucc();
                delete tmp;
            }
            size--;
        }
        bool isFull(){
            return size>=max;
        }
        bool isEmpty(){
            return size==0;
        }
        void print(){
            if(testa){
                Nodo* iter=testa;
                while(iter!=NULL){
                    cout << iter->getElemento() << " ";
                    iter=iter->getSucc();
                }
                cout << endl;
            }
        }
};

class StackOfPlates{
    private:
        vector<Stack*> plates;
    public:
        StackOfPlates(){
            plates.push_back(new Stack());
        }
        void insert(int val){
            for(int i=0; i<plates.size(); i++){
                if(!plates[i]->isFull()){
                    plates[i]->push(val);
                    return;
                }
            }
            plates.push_back(new Stack());
            plates[plates.size()-1]->push(val);
        }
        void remove(){
            for(int i=plates.size()-1; i>=0; i--){
                if(!plates[i]->isEmpty()){
                    plates[i]->pop();
                    return;
                }
                else{
                    plates.erase(plates.begin()+i);
                }
            }
        }
        void printPlates(){
            for(int i=0; i<plates.size(); i++){
                cout << "plate " << i+1 << endl;
                plates[i]->print();
            }
            cout << endl;
        }
};

int main(){
    StackOfPlates* plates = new StackOfPlates();
    plates->insert(10);
    plates->insert(2);
    plates->insert(5);
    plates->insert(1);
    plates->insert(4);
    plates->insert(12);
    plates->remove();
    plates->remove();
    plates->remove();
    plates->printPlates();
    return 0;
}