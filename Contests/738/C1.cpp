#include<bits/stdc++.h>
#define FOR(n) for(int i=0;i<n;++i)
#define FOR1(n) for(int i=1;i<n;++i)
#define FR(i,n) for(int i=0;i<n;++i)
#define rng(a,b) for(int i=a;i<b;++i)
#define ll long long 
#define vint vector<int>
#define vbool vector<bool>
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
    #else
    #endif
 
    int n,m1,m2;
    cin>>n>>m1>>m2;

    DSU val1(n+1),val2(n+1);
    FOR(m1){
        int u,v;
        cin>>u>>v;
        val1.merge(u,v);
    }
    FOR(m2){
        int u,v;
        cin>>u>>v;
        val2.merge(u,v);
    }
    vvin ans;
    for(int i=1;i<=n;i++){
        if(val1.find(i)!=val1.find(1) and val2.find(i)!=val2.find(1)){
            ans.PB({1,i});
            val1.merge(i,1);
            val2.merge(i,1);
        }
    }
    vbool vis(n+1,0); 
    vis[1] = 1;
    int l=1,r=1;
    while(l<=n && r<=n){
        while( l<=n && (val1.find(l) == val1.find(1) or vis[val1.find(l)]))l++;
        while( r<=n && (val2.find(r) == val2.find(1) or vis[val2.find(r)]))r++;
        if(l>n or r>n)
            break;
        vis[val1.find(l)] = vis[val2.find(r)] = true;
        
        val1.merge(l,r);
        val2.merge(l,r);
        ans.PB({l,r});

    }
    cout<<ans.size()<<endl;
    for(auto it:ans)
        cout<<it[0]<<" "<<it[1]<<endl;
    
}
