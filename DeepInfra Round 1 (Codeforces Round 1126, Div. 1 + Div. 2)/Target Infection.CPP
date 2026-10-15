#include<bits/stdc++.h>
using namespace std ; 
using ll = long long ;

bool infected(ll x, const vector<pair<ll, ll>>& seg,
              const vector<ll>& starts) {
    int i = int(upper_bound(starts.begin(), starts.end(), x)
                - starts.begin()) - 1;

    return i >= 0 && seg[i].second >= x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n ; 
        ll m , k ;
        cin>>n>>m>>k;
        vector<pair<ll, ll>> seg(n);
        vector<ll> starts(n);
        ll maxR =0 ; 
        for(int i =0 ; i<n ; i++){
            cin>>seg[i].first >>seg[i].second ; 
            starts[i] = seg[i].first ; 
            maxR = max(maxR , seg[i].second) ; 
        }
        if(k==0){
            cout<<maxR+1<<'\n';
            continue;
        }
        ll f = 0 ; 
        for (auto [l, r] : seg){
            if(l>m) break ;
            ll right = min(r, (ll)m);
            if(l<=right){
                f += right -l +1 ;
            }

        }
        vector<ll> points ={1 , maxR +1};
        auto addPoint =[&](ll p){
            if(p>1 && p <= maxR+1){
                points.push_back(p);
            }
        };
        for(auto [l , r ] :seg){
            addPoint(l);
            addPoint(r+1);
            addPoint(l-m);
            addPoint(r-m+1);
        }
        sort(points.begin(),points.end());
        points.erase(
            unique(points.begin(),points.end()),
            points.end()
        );
        ll ans = -1 ; 
        for(int i = 0 ; i+1<(int)points.size();i++){
            ll L = points[i];
            ll R = points[i+1];
            ll len = R-L ; 
            int d = int(infected(L+m , seg , starts)) 
            - int(infected(L,seg,starts));
            if(d==0){
                if(f==k){
                    ans =L ;
                    break ; 

                }
            }
            else if(d==1){
                if (f <= k && k <= f + len - 1){
                    ans = L +(k-f);
                    break ; 
                }
            }
            else{
                if(f - (len-1) <= k && k <= f){
                    ans = L +(f-k);
                    break ; 
                }
            }
            f += 1LL * d * len ; 

        }
        cout<<ans<<'\n';
    }
    return 0 ; 

}