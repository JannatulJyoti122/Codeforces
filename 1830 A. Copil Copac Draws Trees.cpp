#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll tt;
    cin>>tt;
    while(tt--){
        ll n;
        cin>>n;
        ll dp[n+1];
        for(ll i=1;i<=n;i++)
            dp[i]=0;
        dp[1]=1;
        vector<vector<pair<ll,ll>>>v(n+1);
        for(ll i=0;i<n-1;i++){
            ll x,y;
            cin>>x>>y;
            v[x].push_back({y,i+1});
            v[y].push_back({x,i+1});
        }
        queue<pair<ll,ll>>st;
        st.push({1,0});
        vector<bool>vis(n+1,false);
        while(!st.empty()){
            pair<ll,ll> t1=st.front();
            ll t=t1.first;
            ll ttt=t1.second;
            st.pop();
            vis[t]=true;
            //cout<<t<<" --> ";
            for(ll i=0;i<v[t].size();i++){
                if(vis[v[t][i].first]==true)
                    continue;
                //cout<<v[t][i].first<<" -- "<<v[t][i].second<<" ";
                st.push({v[t][i].first,v[t][i].second});
                if(v[t][i].second>ttt)
                    dp[v[t][i].first]=dp[t];
                else
                    dp[v[t][i].first]=dp[t]+1;
            }
            //cout<<endl;
        }
        ll mx=0;
        for(ll i=1;i<=n;i++)
            mx=max(mx,dp[i]);
        cout<<mx<<endl;
    }
}
