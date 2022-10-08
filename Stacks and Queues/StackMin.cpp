#include <iostream>

using namespace std;

class Nodo{
    private:
        int elemento;
        Nodo* succ;
    public:
        Nodo(int _elemento){
            elemento = _elemento;
            this->succ = NULL;
        }
        int getElemento(){
            return elemento;
        }
        Nodo* getSucc(){
            return succ;
        }
        void setElemento(int x){
            elemento = x;
        }
        void setSucc(Nodo* succ){
            this->succ = succ;
        }
};

class Stack{
    protected:
        Nodo* testa;
    public:
        Stack(){
            testa = NULL;
        }
        void push(int x){
            Nodo* nuovo = new Nodo(x);
            if(testa==NULL)
                testa = nuovo;
            else{
                nuovo->setSucc(testa);
                testa = nuovo;
            }
        }
        void pop(){
            if(testa){
                Nodo* tmp = testa;
                testa = testa->getSucc();
                delete tmp;
            }
        }
        void print(){
            if(testa){
                Nodo* iter = testa;
                while(iter!=NULL){
                    cout << iter->getElemento() << " ";
                    iter = iter->getSucc();
                }
                out << endl;
            }
        }
};

class StackWithMin : public Stack{
    private:
        Stack* s2;
    public:
        StackWithMin(){
            s2 = new Stack();
        }
        void push(int x){
            if(x<=min()){
                s2.push(x);
            }
            Nodo* nuovo = new Nodo(x);
            if(testa==NULL)
                testa = nuovo;
            else{
                nuovo->setSucc(testa);
                testa = nuovo;
            }
        }
        void pop(){
            if(testa){
                Nodo* tmp = testa;
                testa = testa->getSucc();
                if(tmp==min())
                    s2.pop();
                delete tmp;
            }
        }
        int min(){
            if(s2.)
        }
}

int main(){
    return 0;
}