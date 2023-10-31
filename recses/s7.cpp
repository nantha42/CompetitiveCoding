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
    int n,x;
    // freopen("input.txt","r",stdin);
    cin>>n>>x;
    vector<array<int,2>> arr;
    bool found = false;
    map<int,int> mp;
    FOR(n){ 
        int u;cin>>u;
        arr.PB({u,i});
        mp[u]++;
    }
    sort(arr.begin(),arr.end());

    int i=0,j=n-1;
    while(i<j){
        if(arr[i][0] + arr[j][0]>x) j--; 
        else if(arr[i][0] + arr[j][0] < x)i++;
        else if(arr[i][0] + arr[j][0] == x){found = true;break;};
    }

   
   if(found){
        cout<<arr[i][1]+1<<" "<<arr[j][1]+1<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    
    
}