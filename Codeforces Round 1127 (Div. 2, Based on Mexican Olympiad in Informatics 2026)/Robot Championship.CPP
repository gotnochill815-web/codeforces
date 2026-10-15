#include<bits/stdc++.h>
using namespace std ; 
int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    int t ; 
    cin >> t ; 
    while(t--){
        int n ; 
        cin>> n ;
        vector<int> lasers ; 
        int elapsed = 0 ; 
        for(int q = 0 ; q<3 ; q++){
            int offset = (2 * n - (q + elapsed)) % 3;
            if(offset<0){
                offset += 3 ; 
            }
            int u = 2 * n - offset ;
            while(u >= 2){
                lasers.push_back(u) ;
                u -= 2 ;
                elapsed ++ ; 
            }
        }
        cout<<lasers.size()<<'\n' ;
        for(int i =0 ; i< (int)lasers.size() ; i++){
            if(i>0) cout<<' ' ;
            cout<<lasers[i] ;

        }
        cout<<'\n' ; 
    }
    return 0 ; 
    
}