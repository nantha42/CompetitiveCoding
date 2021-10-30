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
    ll n,x;
    cin>>n>>x;
    vlong arr;
    for(int i=0;i<n;i++){
        ll u;cin>>u;arr.PB(u);}
    sort(arr.begin(),arr.end());
    int j =0;  
    vlong dp(x+1,0);
    dp[0] = 0; 
     
    for(int i=1;i<=x;i++){
        ll count = 0;
        for(int j=0;j<n;j++){
            if(arr[j] == i) count+=1;
            if(arr[j] > i) break;
            else{
                if(dp[i-arr[j]]>1)
                    count+=dp[i-arr[j]];
               // count+= (dp[i - arr[j]]);
            }
        }
        dp[i] = (count)%((ll)1e9+7);
        cout<<i<<" "<<dp[i]<<endl;
    }
    cout<<dp[x]<<endl;
    
}
