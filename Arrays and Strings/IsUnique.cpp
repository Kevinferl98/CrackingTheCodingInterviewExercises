#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// O(n^2)
bool check1(string s){ 
    for(int i=0; i<s.length(); i++){
        for(int j=i+1; j<s.length(); j++){
            if(s[i] == s[j])
                return false;
        }
    }
    return true;
}

// O(nlogn)
bool check2(string s){
    string temp = s;
    sort(temp.begin(), temp.end());

    for(int i=0; i<s.length()-1; i++){
        if(s[i]!=s[i+1])
            continue;
        else
            return false;
    }
    return true;
}

// O(n)
bool check3(string s){
    if(s.length()>128)
        return false;
    bool* char_set = new bool[128];
    for(int i=0; i<s.length(); i++){
        int val = s[i];
        if(char_set[val])
            return false;
        char_set[val] = true;
    }
    return true;
}

int main(){
    string prova = "ciao";
    cout << check3(prova) << endl;
    return 0;
}