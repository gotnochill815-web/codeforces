# include<bits/stdc++.h>
using namespace std ; 
using ll = long long ; 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t ; 
    while(t--){
        int n ; 
        cin>>n ; 
        vector<ll> a(n) ;
        for(int i =0 ; i<n ; i++){
            cin>>a[i];
        }
        ll mn = a[0] ;
        ll mx = a[0] ;
        ll ans = a[0] ;
        for(int i =1 ; i<n ; i++){
            ll bestAbs = max(abs(mn), abs(mx)) ;
            ans = max(ans , a[i]+bestAbs);
            ll newMn = min({
                a[i] , mn + a[i] , 2 * mn + a[i]
            });
            ll newMx = max({
                a[i] ,
                mx + a[i] , 
                2 * mx + a[i]
            });
            mn = newMn ;
            mx = newMx ;

        }
        cout<<ans <<"\n" ;
    }
    return 0 ; 
}