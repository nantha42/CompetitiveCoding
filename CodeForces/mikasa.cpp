#include<bits/stdc++.h>
#define FOR(n) for(int i=0;i<n;++i)
#define FOR1(n) for(int i=1;i<n;++i)
#define ll long long 
#define vint vector<int>
#define vlong vector<long long>
#define vstr vector<string>
#define vvin vector<vector<int>>
#define PB push_back
#define nl "\n"
#define F first
#define S second
#define sortit(x) sort(x.begin(),x.end())
using namespace std;

bool ISPRIME(long long n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return false;
    } 
    return true; 
}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    int t;cin>>t;
    while(t--){
       ll n,m;
       cin>>n>>m;
       //cout<<n<<" "<<m<<endl;
       cout<<"-----"<<endl;
       if(m<n){
          cout<<0<<endl; 
          continue;
       }
       bool f = false;
       ll x = 1;
       while(x<=m){
          if( ((x-1)^n) < max(n,m) && ((x-1) >m))
              break;
          x<<=1;
          
       }
       cout<<((x-1)^n)<<endl;
        cout<<"###"<<endl;
       for(int i=0;i<=max(n,m);i++){
            ll p = i^n; 
            cout<<i<<" "<<n<<" "<<p<<endl;
            if(p>m){
                cout<<i<<endl;
                f=true;
                break;
                }
       } 
       if(!f) 
       cout<<n+1<<endl;
       
    }
  
}


