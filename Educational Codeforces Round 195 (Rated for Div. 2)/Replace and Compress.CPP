#include<bits/stdc++.h>
using namespace std ; 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; 
    cin>>t ; 
    while (t--)
    {
    
        string s ; 
        cin>>s ; 
        int n = s.size() ; 
        bool canincrease = false ; 
        bool canidecrese = false ; 
        for(int i = 1 ; i<n-1 ; i++){
            if(s[i-1]==s[i]&& s[i] == s[i+1]){
                canincrease = true ; 

            }
            if(s[i-1]== s[i+1]&& s[i]!=s[i-1]){
                canidecrese = true ; 
            }
        }
        int ans = 1 + canidecrese + canincrease ;
        cout<<ans << '\n' ;
    }
    return 0 ; 
    
}