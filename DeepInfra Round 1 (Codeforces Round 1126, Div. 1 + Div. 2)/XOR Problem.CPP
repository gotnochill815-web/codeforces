#include<bits/stdc++.h>
using namespace std ;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin>>t;
    while(t--){
        int n ; 
        cin>>n ; 
        int q=1 ; 
        while(q<=n){
            q*=2;

        }
        vector<int> pref ; 
        pref.reserve(2*q);
        for(int i = 0 ; i<q ; i++){
            pref.push_back(i^(i>>1));
        }
        for(int i = 0 ; i<q ; i++){
            pref.push_back(i^(i>>1));
        }
        cout<<2*q-1<<'\n';
        for(int i =1 ; i<(int)pref.size();i++){
            cout<<(pref[i-1]^pref[i]);
            cout<<(i+1==(int)pref.size()?'\n':' ');
        }
    }
    return 0 ; 
}