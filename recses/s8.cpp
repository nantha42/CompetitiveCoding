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
#define sortit(x) sort(x.begin(),x.end())
#define F first
#define S second
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
    vint arr(t,0);
    FOR(t)cin>>arr[i];
    ll maxvalue = -1e9;

    int i=0,j=0;
    maxvalue = arr[i];
    ll sum = arr[i];

    for(j=1;j<t;j++){
        // cout<<sum<<endl;
        if(sum < 0){
            i = j;
            sum = arr[j];
        }else {
            sum += arr[j];
        }
        maxvalue = max(maxvalue,sum);
    }
    cout<<maxvalue<<endl; 

}