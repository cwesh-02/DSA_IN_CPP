#include<bits/stdc++.h>
using namespace std;
vector<long long int> extra(vector<long long int> &arr){
    int z = 0;
    for(long long int i = 0; i < arr.size(); i++){
        if(arr[i]==0)z++;
    }
    for(long long int i = 0; i < arr.size(); i++){
        if(z==0)break;
        if(arr[i]==0){
            arr.erase(arr.begin()+i);
            i--;
            arr.push_back(0);
            z--;
        }
    }
        return arr;
}

int main(){
    int n;
    cin>>n;
    vector<long long int>arr(n);
    for(int i = 0; i < n; i++){
        long long int t;cin>>t;
        arr[i]=t;
    }
    vector<long long int>a =  extra(arr);
    for(auto i : a){
        cout<<i<<" ";
    }
    cout<<endl;
}