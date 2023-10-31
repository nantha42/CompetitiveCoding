#include<bits/stdc++.h>
#define FOR(n) for(int i=0;i<n;++i)
#define FOR1(n) for(int i=1;i<n;++i)
#define ll long long 
#define vint vector<int>
#define vlong vector<long long>
#define vstr vector<string>
#define vvin vector<vector<int>>
#define PB push_back
#define nl 

using namespace std;

bool ISPRIME(long long n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return false;
    } 
    return true; 
}
bool search(vint &app,int x,int k){
    int l = 0,r = app.size()-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(app[mid]>(x+k))
            r = mid-1;
        else if(app[mid]<(x-k))
            l = mid+1;
        else if (app[mid]>=(x-k) && app[mid]<=(x+k)){
            app.erase(app.begin()+mid);
            return true;
        }
    }
    return false;
}
int main(){
    ll t;
    // freopen("input.txt","r",stdin);
    cin>>t;
    while(t--){
        ll x,y;cin>>x>>y;
        ll m = max(x,y);
        ll n= (m-1)*(m-1);
        if(m%2==0){
            if(x >= y){
                n = n+ m;
                n = n+ (m-y);
            }else {
                n = n+x;
            }
            cout<<n<<endl;
        }
        else{
            if(x < y){
                n = n+m;
                n = n + (m-x);
            }
            else n = n+y;
            cout<<n<<endl;
        }
    }	
}