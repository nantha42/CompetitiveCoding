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
    int t;
    // freopen("input.txt","r",stdin);
    cin>>t;
    vint a;
    vint b;
    ll as = 0,bs = 0;
    for(int i=t;i>=1;i--){
       if(as <= bs){
           a.PB(i);
           as += i;
       }
       else{
           b.PB(i);
           bs += i;
       }
    }
    if(as == bs){
        cout<<"YES"<<endl;
        cout<<a.size()<<endl;
        FOR(a.size())cout<<a[i]<<" ";
        cout<<endl;
        cout<<b.size()<<endl;
        FOR(b.size())cout<<b[i]<<" ";
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
