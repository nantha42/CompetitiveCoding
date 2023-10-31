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
    long long unsigned t;
    cin>>t;
    while(t!=1){
        cout<<t<<" ";
        if(t%2) t = t*3+1;
        else t = t/2;

    }
    cout<<t<<endl;
}