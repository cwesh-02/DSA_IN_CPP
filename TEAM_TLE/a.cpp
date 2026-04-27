#include<bits/stdc++.h>
using namespace std;
bool extra(string s){
    vector<int>arr;
    for(int i = 0; i < s.length(); i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            arr.push_back(s[i]);
        }
        else{
            if(s[i]==')'){
                if(arr.size()==0||arr[arr.size()-1]!='('){
                    return false;
                }
                else{
                    arr.pop_back();
                }
            }
            if(s[i]=='}'){
                if(arr.size()==0||arr[arr.size()-1]!='{'){
                    return false;
                }
                else{
                    arr.pop_back();
                }
            }
            if(s[i]==']'){
                if(arr.size()==0||arr[arr.size()-1]!='['){
                    return false;
                }
                else{
                    arr.pop_back();
                }
            }
        }
    }
    if(arr.size()==0)return true;
    return false;
}

int main(){
    string s;
    cin>>s;
    cout<<extra(s)<<endl;
}