#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll m=998244353;
int main(){
    ll tt;
    cin>>tt;
    while(tt--){
        ll n;
        cin>>n;
        getchar();
        string s;
        cin>>s;
        ll extra=0;
        ll tot=1;
        ll start=1;
        for(ll i=1;i<n;i++){
            if(s[i]==s[i-1]){
                start=(start*2)%m;
                extra=(extra+start)%m;
            }
            else{
                start=1;
                tot++;
                tot%=m;
            }
        }
        cout<<(tot+extra)%m<<endl;
    }
}
