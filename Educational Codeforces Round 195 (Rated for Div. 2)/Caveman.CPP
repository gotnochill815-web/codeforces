#include<bits/stdc++.h>
using namespace std ; 
int main(){
    ios::sync_with_stdio(false) ; 
    cin.tie(nullptr) ;
    int t ; 
    cin>>t  ; 
    while(t--){
        int n , m;
        cin>>n >> m ; 
        vector<int> deg(n,0);
        for(int i = 0 ; i<m ; i++){
            int u , v ; 
            cin>>u>>v ;
            --u ;
            --v ;
            deg[u]++;
            deg[v]++;
        }
        bool isolated = false ; 
        for(int i =0 ; i<n ; i++){
            if(deg[i]==0){
                isolated = true ; 
                break ; 
            }
        }
        if(isolated){
           cout<<"Brain Melt \n" ;
           continue;
        }
        bool star = false ; 
        for(int i =0 ; i<n ; i++){
            if(deg[i]==n-1){
                star = true ; 
                for(int j = 0 ; j<n ; j++){
                    if(j!= i && deg[j]!= 1){
                        star = false ; 
                        break ; 
                    }
                }
                break ; 
            }
        }
        if(star){
            cout<<"2\n";
        }
        else{
            cout<<"Many\n" ;
        }
    }
    return 0 ; 

}
