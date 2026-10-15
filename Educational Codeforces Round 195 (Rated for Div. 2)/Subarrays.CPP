#include<bits/stdc++.h>
using namespace std ; 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; 
    cin>>t;
    while(t--){
        int n , k ; 
        cin>>n>>k ; 
        vector<int> a(n) ;
        for(int i = 0 ; i<n ; i++){
            cin>>a[i] ; 
        }
        vector<int> pref(n+1 , 0 );
        for(int i =1 ; i<=n ; i++){
            pref[i] = (pref[i-1]+ a[i-1] % k )%k ; 

        }
        vector<long long > freq(k,0) ; 
        long long ans =0;
        for(int j = 0 ;j<=n ; j++){
            int idx = j-k-1 ; 
            if(idx>=0){
                freq[pref[idx]]++ ;
            }
            ans += freq[pref[j]] ;

        }
        cout<<ans<<'\n' ;
    }
    return 0 ; 
}