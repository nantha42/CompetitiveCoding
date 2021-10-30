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
void dfs(vbool &vis,vvin &t,int i,vint &st,int type){
  vis[i] = true; 
  st[i] = type;
  for(auto x:t[i]){
   if(vis[x]==false){
    dfs(vis,t,x,st,type);
   } 
  }
    

}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    #else
    #endif
    int n,m1,m2;
    cin>>n>>m1>>m2;
    vvin t1(n),t2(n);
    FOR(m1){
        int u,v;
        cin>>u>>v;
        t1[u-1].PB(v-1);
        t1[v-1].PB(u-1);
    }
    FOR(m2){
        int u,v;
        cin>>u>>v;
        t2[u-1].PB(v-1);
        t2[v-1].PB(u-1);
    }
    vector<set<int>> s1,s2;
    vbool b1(n,false),b2(n,false);
    vint set1(n,-1),set2(n,-1);

    //building sets
    int type = 0;
    for(int i=0;i<n;i++){
        if(b1[i]==false){
            dfs(b1,t1,i,set1,type);
        }
        type++;
    }
    type = 0;
     for(int i=0;i<n;i++){
        if(b2[i]==false){
            dfs(b2,t2,i,set2,type);
        }
        type++;
    }
    vvin ans;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(set1[i]!=set1[j] && set2[i] != set2[j]){
//                cout<<i+1<<" "<<j+1<<endl;
                ans.PB({i+1,j+1});
                type = set1[j];
                FR(k,n){
                    if(type==set1[k])
                        set1[k] = set1[i];
                }
                type = set2[j];
                FR(k,n){
                    if(type==set2[k])
                        set2[k] = set2[i];
                }
                
            }
        }
    }
    cout<<ans.size()<<endl;
    FOR(ans.size())
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
     
        


//        if(f)
//            cout<<"YES"<<endl;
//        else cout<<"NO"<<endl;
	
}

