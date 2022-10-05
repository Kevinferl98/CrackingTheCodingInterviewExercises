#include <iostream>

using namespace std;

bool metodo(string s){
    int* table = new int['z'-'a'+1];
    int oddCount = 0;

    for(int i=0; i<s.length(); i++){
        if(s[i]!=' '){
            table[s[i]]++;
            if(table[s[i]]%2==1)
                oddCount++;
            else
                oddCount--;
        }
    }
    if(oddCount<=1)
        return true;
    else
        return false;
}

int main(){
    string prova = "tact coa";
    cout << metodo(prova) << endl;
    return 0;
}