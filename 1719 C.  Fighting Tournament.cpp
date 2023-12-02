#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll tt;
    cin>>tt;
    while(tt--){
        ll n,q;
        cin>>n>>q;
        ll a[n];
        for(ll i=0;i<n;i++)
            cin>>a[i];
        map<ll,pair<ll,ll>>mp;
        ll mx=a[0];
        ll ind=1;
        mp[ind].first=1;
        mp[ind].second=1;
        for(ll i=1;i<n;i++){
            if(a[i]<mx){
                mp[i+1].first=0;
                mp[i+1].second=0;
                mp[ind].second++;
            }
            else{
                mp[i+1].first=mp[ind].second;
                mp[i+1].second=mp[ind].second+1;
                mx=a[i];
                ind=i+1;
            }
        }
        mp[ind].second=1e9;
        vector<ll>v;
        for(ll i=0;i<q;i++){
            ll x,y;
            cin>>x>>y;
            if(y<mp[x].first)
                v.push_back(0);
            else{
                if(y<mp[x].second)
                    v.push_back(y-mp[x].first+1);
                else
                    v.push_back(mp[x].second-mp[x].first);
            }
        }
        for(ll i=0;i<q;i++)
            cout<<v[i]<<endl;
    }
}
