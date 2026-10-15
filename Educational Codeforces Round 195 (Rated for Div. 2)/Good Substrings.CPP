#include<bits/stdc++.h>
using namespace std ; 
using ll = long long ; 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr) ;
    int t ; 
    cin>>t ; 
    while(t--){
        int n ; 
        string s ; 
        cin>>n>>s; 
        vector<int>nxt0(n+1, n );
        vector<int>nxt2(n+1, n );
        vector<int>nxt5(n+1, n );
        vector<int>nxt6(n+1, n );
        for(int i = n-1 ; i>=0 ;i--){
            nxt0[i] = nxt0[i+1] ; 
            nxt2[i] = nxt2[i+1] ;
            nxt5[i] = nxt5[i+1] ;
            nxt6[i] = nxt6[i+1] ;
            if(s[i]=='0')nxt0[i] = i ; 
            if(s[i]=='2')nxt2[i] = i ;
            if(s[i]=='5')nxt5[i] = i ;
            if(s[i]=='6')nxt6[i] = i ;
        }
        vector<ll> diffConst(n+1 , 0 ); 
        vector<ll> diffSlope(n+1 , 0 ); 
        for(int l = 0 ; l<n ; l++){
            int p = nxt2[l];
            if(p == n) continue;
            p = nxt0[p + 1];
            if(p == n) continue;
            p = nxt2[p + 1];
           if(p == n) continue;
           int end5 = nxt5[p + 1];
           if (end5 == n) continue;
           int q = nxt2[l];
           if(q == n) continue;
           q = nxt0[q + 1];
           if(q == n) continue;
           q = nxt2[q + 1];
           if(q == n) continue;
           int end6 = nxt6[q + 1];
           if (end5 < end6) {
                ll cnt = end6 - end5 ; 
                diffConst[l] += cnt ; 
                diffConst[end5] -= cnt ; 
                diffConst[end5] += end6 ; 
                diffConst[end6] -= end6 ;
                diffSlope[end5] -= 1;
                diffSlope[end6] += 1;
            }
        }
        ll currentConst = 0 ; 
        ll currentScope = 0 ; 
        for(int i = 0 ; i<n ; i++){
            currentConst += diffConst[i];
            currentScope += diffSlope[i];
            ll bad = currentConst + currentScope * i ; 
            ll total = 1LL * (i+1) * (n-i) ; 
            cout<<total-bad ; 
            if(i+1 < n )cout<<' ' ;
        }
        cout<<'\n' ; 
    }
    return 0 ; 


}