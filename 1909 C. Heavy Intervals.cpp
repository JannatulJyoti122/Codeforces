#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
int main(){
    ll tt;
    cin>>tt;
    while(tt--){
        ll n;
        cin>>n;
        vector<pair<ll,char>>total_array;
        vector<ll>l(n),r(n),c(n);
        for(ll i=0;i<n;i++)
            cin>>l[i];
        for(ll i=0;i<n;i++)
            cin>>r[i];
        for(ll i=0;i<n;i++)
            cin>>c[i];
        for(ll i=0;i<n;i++){
            total_array.push_back({l[i],'l'});
            total_array.push_back({r[i],'r'});
        }
        sort(c.begin(),c.end());
        sort(total_array.begin(),total_array.end());
        vector<ll>v,temp;
        for(ll i=0;i<(2*n);i++){
            if(total_array[i].second=='l')
                temp.push_back(total_array[i].first);
            else{
                v.push_back(total_array[i].first-temp[temp.size()-1]);
                temp.pop_back();
            }
        }
        sort(v.begin(),v.end());
        ll tot=0;
        for(ll i=n-1;i>=0;i--){
            tot+=c[n-1-i]*v[i];
            cout<<v[i]*c[n-1-i]<<" ";
        }
        cout<<tot<<endl;
    }
}
