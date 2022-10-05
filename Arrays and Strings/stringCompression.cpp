#include <iostream>
#include <string>

using namespace std;

string metodo(string s){
    int* charset = new int[128];
    string ret = "";

    for(int i=0; i<s.length(); i++){
        charset[s[i]-'a']++;
    }

    for(int i=0; i<128; i++){
        if(charset[i]!=0){
            cout << "Aggiungo " << char(i+'a') << endl; 
            ret += char(i+'a');
            ret += to_string(charset[i]);
        }
    }
    if(ret.length()<s.length())
        return ret;
    else
        return s;
}

int main(){
    string s = "aabcccccaaa";

    cout << metodo(s) << endl;

    return 0;
}