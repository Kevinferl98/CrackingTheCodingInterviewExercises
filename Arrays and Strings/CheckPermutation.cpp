#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// O(n logn)
bool metodo1(string s1, string s2){
    if(s1.length()!=s2.length())
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for(int i=0; i<s1.length(); i++){
        if(s1[i]!=s2[i])
            return false;
    }
    return true;
}

// O(n)
bool metodo2(string s1, string s2){
    if(s1.length()!=s2.length())
        return false;
    
    int* char_set = new int[128];

    for(int i=0; i<s1.length(); i++){
        char_set[s1[i]-'a']++;
    }

    for(int i=0; i<s2.length(); i++){
        char_set[s2[i]-'a']--;
    }

    for(int i=0; i<128; i++){
        if(char_set[i]!=0)
            return false;
    }
    return true;
}

int main(){
    string s1 = "ciao";
    string s2 = "aioc";

    cout << metodo2(s1, s2) << endl;
    return 0;
}