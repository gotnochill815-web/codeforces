#include<bits/stdc++.h>
using namespace std ; 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; 
    cin>>t ; 
    while(t--){
        int a,b ;
        cin>>a>>b;
        if(b<=a && (a+b)%2==0){
            cout<<a<<'\n' ;
        } 
        else if(b<=a+1){
            cout<<a+1<<'\n' ;
        }
        
        else{
            cout<<-1<<'\n' ; 
        }
    }
    return 0 ; 
    
}