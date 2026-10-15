#include<bits/stdc++.h>
using namespace std ; 
using ll = long long ; 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; 
    cin>>t ; 
    while(t--){
        int n ; 
        ll k ; 
        cin>> n >> k ; 
        multiset<ll> s;
        for(int i = 0 ; i<n ; i++){
           ll x ; 
           cin>>x;
           s.insert(x);
        }
        ll ans = 0 ; 
        while(!s.empty()){
            auto it = s.begin() ;

            if(*it <= k ){
                s.erase(it) ;

            }
            else {
                auto largest = prev(s.end());
                ll x = *largest;

                s.erase(largest);
                s.insert(x / 2);
                s.insert(x / 2);
}
            ans++ ; 
            k++;
        }
        cout<< ans << '\n' ; 
    }
    return 0 ; 
}