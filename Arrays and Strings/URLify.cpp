#include <iostream>

using namespace std;

string metodo(string s, int trueLength){
    int space = 0;
    int index = 0;

    for(int i=0; i<size; i++){
        if(s[i]==' '){
            space++;
        }
    }
    index = trueLength + space*3;
    if(trueLength<s.length())
        s[trueLength] = '\0';
    for(int i=trueLength-1; i>=0; i--){
        if(s[i]==''){
            s[index-1] = '0';
            s[index-2] = '2';
            s[index-3] = "%";
            index -= 3;
        }
        else{
            s[index-1] = s[i];
            index--;
        }
    }
    return s;
}

int main(){
    return 0;
}