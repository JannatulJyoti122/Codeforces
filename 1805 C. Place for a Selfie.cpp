#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll tt;
    cin>>tt;
    while(tt--){
        ll n,m;
        cin>>n>>m;
        vector<ll>v;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        for(ll i=0;i<m;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            bool check=false;
            ll co=0;
            ll temp=4*a*c;
            if(temp<=0){
                cout<<"NO\n";
                continue;
            }
            ll p=ceil(sqrt(temp*1.0));
            ll t1=b+p;
            ll t2=b-p;
            ll low=min(t1,t2);
            ll ind=upper_bound(v.begin(),v.end(),low)-v.begin();
            if(ind<n&&v[ind]<max(t1,t2)){
                check=true;
                co=v[ind];
            }
            if(check){
                cout<<"YES\n";
                cout<<co<<endl;
           }
            else
               cout<<"NO\n";
        }
        cout<<endl;
    }
}
