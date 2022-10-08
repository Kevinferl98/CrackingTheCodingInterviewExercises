#include <iostream>

using namespace std;

class FixedMultiStack{
    private:
        int numberOfStacks = 3;
        int stackCapacity;
        int* values;
        int* sizes;
    public:
        FixedMultiStack(int stackSize){
            stackCapacity = stackSize;
            values = new int[stackSize*numberOfStacks];
            sizes = new int[numberOfStacks];
        }

        void push(int stackNum, int value){
            if(isFull(stackNum))
                return;
            sizes[stackNum]++;
            values[indexOfTop(stackNum)] = value;
        }

        int pop(int stackNum){
            if(isEmpty(stackNum))
                return -1;
            int topIndex = indexOfTop(stackNum);
            int value = values[topIndex];
            values[topIndex] = 0;
            sizes[stackNum]--;
            return value;
        }

        int peek(int stackNum){
            if(isEmpty(stackNum))
                return -1;
            return values[indexOfTop(stackNum)];
        }

        bool isEmpty(int stackNum){
            return sizes[stackNum] == 0;
        }

        bool isFull(int stackNum){
            return sizes[stackNum] == stackCapacity;
        }

        int indexOfTop(int stackNum){
            int offset = stackNum * stackCapacity;
            int size = sizes[stackNum];
            return offset + size -1;
        }

        void print(){
            for(int i=0; i<stackCapacity*numberOfStacks; i++)
                cout << values[i] << " ";
            cout << endl;
        }
};

int main(){
    FixedMultiStack* stack = new FixedMultiStack(2);
    stack->push(0,3);
    stack->print();
    stack->push(0,7);
    stack->push(1, 12);
    stack->push(2, 32);
    stack->print();
    stack->pop(0);
    stack->print();
    return 0;
}