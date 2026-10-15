#include<bits/stdc++.h>
using namespace std ; 
using ll = long long ; 
ll capacity(int k ){
    ll total = 0 ; 
    for(int s = 1 ; s <= k ; s++){
        total += 1LL * s * (k/s) ;
    }
    return total ;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; 
    cin >> t ;
    while(t--){
        int n ; 
        cin>>n ; 
        int low = 1 , high = n ; 
        while(low<high){
            int mid = low + (high - low ) / 2 ;
            if(capacity(mid) >= n){
                high = mid ; 
            }
            else{
                low = mid + 1 ; 
            }
        }
        int k = low ; 
        vector<int> cnt(k+1 , 0 );
        int remaining = n ; 
        for(int s = k ; s >= 1 ; s--){
           int take = min(k / s , remaining / s) ;
           cnt[s] = take ;
           remaining -= take * s ; 
        }
        vector<int> a ; 
        int value = 1 ;
        for(int s = 1 ; s <= k ; s++){
            for(int j = 0 ; j < cnt[s] ; j++){
                for(int p = 0 ; p < s ; p++){
                    a.push_back(value);
                }
                value ++ ; 
            }
        }
        cout<< k << '\n' ;
        for(int i = 0 ; i < n ; i++){
            if (i) cout<<' ' ;
            cout << a[i] ; 
        }
        cout<< '\n' ;
    }
    return 0 ; 

}