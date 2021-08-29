#include<bits/stdc++.h>
#define FOR(n) for(int i=0;i<n;++i)
#define FOR1(n) for(int i=1;i<n;++i)
#define FR(i,a,b) for(int i=a;i<b;++i)
#define rng(a,b) for(int i=a;i<b;++i)
#define ll long long 
#define vint vector<int>
#define vlong vector<long long>
#define vstr vector<string>
#define vvin vector<vector<int>>
#define PB push_back
#define nl "\n"
#define F first
#define S second
#define __ << " " << 
#define ar array
#define sortit(x) sort(x.begin(),x.end())
#define umap unordered_map
using namespace std;
template <typename T>
void insert(vector<T> &vec, T x ){
    auto it = vec.lower_bound(x);
    vec.insert(it,x);
}
bool ISPRIME(long long n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return false;
    } 
    return true; 
}
void swap(int &a,int &b){
    int t=a;
    a=b;
    b=t;
}
struct DSU{
    int n;
    vint p;
    DSU(int N){
        n = N;
        p.assign(n+1,-1);
        for(int i=0;i<=n;++i)p[i] = i;
    }
    int find(int i){
        if(p[i]==i)return i;
        return p[i] = find(p[i]);
    }
    void merge(int a,int b){
        a = find(a),b = find(b);
        if(a!=b) p[b] = a;
    }
};
// 3 5
// 8 0 
// 0 0 
// 16 -16
// 8 -8  
// 4 -4
// -1 1
int work(vint &arr,int i,int l=0){
    int c=0;
//    cout<<i<<" ";
      FOR(arr.size())
          cout<<arr[i]<<" ";
      cout<<endl;
 
    if(i-2>=0 and arr[i-1]==arr[i-2] and arr[i]!=arr[i-1] and l!=2)
    {
        c=1;
        swap(arr[i],arr[i-1]);
        c+=work(arr,i-1,1);
        c+=work(arr,i);

    }
    else if(i+2<arr.size() and arr[i+1]==arr[i+2] and arr[i]!=arr[i+1] and l!=1){
        c=1;
       swap(arr[i],arr[i+1]); 
       c+=work(arr,i+1,2);
       c+=work(arr,i);
    }
    return c;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #else
    #endif
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;  
      vint arr(n);
      int o=0,e=0;
      FOR(n){
          cin>>arr[i];
          if(arr[i]%2){
              arr[i]=1;
              o+=1;
          }
          else{ 
              arr[i] = 0;
              e+=1;
          }
      }
      if(o!=n/2 and o!=n/2+1){
          cout<<-1<<endl;
          continue;
      }
      if(n==1){cout<<0<<endl; continue;}
      int ans=0;
      FOR(n){
        ans+=work(arr,i); 
      } 
      FOR(n)
          cout<<arr[i]<<" ";
      cout<<endl;
      cout<<ans<<endl; 
    }
    
}

