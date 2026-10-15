#include<bits/stdc++.h>
using namespace std ; 
int main(){
    int t; 
    cin>>t ; 
    while (t--)
    {
        int n ; 
        cin>>n ; 
        vector<long long > b(n) ; 
        for(int i = 0 ; i<n ; i++){
            long long a ; 
            cin>>a;
            b[i] = a -(i+1) ;
        }
        sort(b.begin() , b.end()) ;
        int ans = 1;
        int current = 1;
        for(int i =1 ; i<n ; i++){
            if(b[i]==b[i-1] +1){
                current++; 
                ans = max(ans , current) ;
            }
            else if(b[i] != b[i-1]){
                current = 1; 
            }
        }
        cout<<ans<<"\n" ;
    }
    return 0 ; 
    
     
}