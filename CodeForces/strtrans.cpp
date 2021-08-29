#include<bits/stdc++.h>
#define FOR(n) for(int i=0;i<n;++i)
#define FOR1(n) for(int i=1;i<n;++i)
#define dbg(x...) cerr << "[" <<    #x << "] = ["; _print(x)
#define FR(i,n) for(int i=1;i<n;++i)
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
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    #else
    #endif
    int t;
    cin>>t;
    while(t--){
       string s;
       cin>>s; 
       int l = s.size();
       map<char,int> mp; 
       int sm=0;
       int v=0;
       string order="";
       bool found[26]={false};
       for(int i=s.size()-1;i>=0;i--)
          if(!found[s[i]-'a']){
              found[s[i]-'a']=true;
              order+=s[i]; 
          }
       reverse(order.begin(),order.end());
       string ans="";
       FOR(s.size()){
           mp[s[i]]+=1;
           sm+=1;
           int v=i+1;
           int a=v;
           for(int j=0;j<order.size();++j){
                a += (v-mp[order[j]]); 
                v -= mp[order[j]]; 
           }
           if(a==s.size()){
               memset(found,false,sizeof found);
               string temp=s.substr(0,i+1);
               string T=temp;
               for(int j=0;j<order.size();j++){
                    found[order[j]-'a']=true;
                    for(int k=0;k<temp.size();k++){
                       if(found[temp[k]-'a']==false)
                          T+=temp[k]; 
                    } 
                    
               }
               if(T==s){
                   ans=temp;
                   break;
               }
           }
       }
       if(ans=="")
          cout<<-1<<endl; 
       else cout<<ans<<" "<<order<<endl;
       //cout<<order<<endl;
 //      cout<<s<<endl;
    }
}

