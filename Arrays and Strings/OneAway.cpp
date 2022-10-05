#include <iostream>

using namespace std;

bool oneEditAway(string s1, string s2){
    if(s1.length()==s2.length())
        return replace(s1, s2);
    else if(s1.length()+1==s2.length())
        return insert(s1, s2);
    else if(s1.length()-1==s2.length())
        return insert(s2, s1);
    return false;
}

bool replace(string s1, string s2){
    if(s1.length()!=s2.length())
        return false;
    int count = 0;

    for(int i=0; i<s1.length(); i++){
        if(s1[i]!=s2[i]){
            if(count==1)
                return false;
            else
                count++;
        }
    }
    return true;
}

bool insert(string s1, string s2){
    int longer = s1.length() < s2.length() ? s2.length() : s1.length();
    int shorter = s1.length() < s2.length() ? s1.length() : s2.length();
    int diff = longer - shorter;
    if(diff>1)
        return false;
    int count = 0;

    for(int i=0; i<shorter; i++){
        if(s1[i]!=s2[i]){
            count++;
        }
    }
    
}

int main(){
    string s1 = "pale";
    string s2 = "bake";

    cout << replace(s1, s2) << endl;
    return 0;
}