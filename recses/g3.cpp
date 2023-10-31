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
	int n,m;
	freopen("input.txt","r",stdin);
	cin>>n>>m;
	vector<pair<int,int>> roads;
	vector<bool> conn(n,false);
	vector<int> group(n,-1);
	vector<pair<int,int>> newroads;


	FOR(m){
		int x,y;cin>>x>>y;
		roads.PB({x-1,y-1});
	}
	sort(roads.begin(),roads.end());
	// for(auto x:roads){
	// 	cout<<x.F+1<<" "<<x.S+1<<endl;
	// }
	for(auto road:roads){
		int x=road.F,y = road.S;
		// cout<<x<<" "<<y<<endl;
		if(x<y){
			if(group[x] == -1 && group[y]== -1){	
				if(x<y){
					group[y] = x;
					group[x] = x;
				}
			}
			// else if( ( group[x] != -1 || group[y] != -1 ) && group[x] != group[y]){
			// 	if(group[y] != -1){
			// 		group[x] = group[y];
			// 	}else{
			// 		group[y] = group[x];
			// 	}
			// }
			else if(group[x] == -1 || group[y] == -1){
				if(group[y] != -1){
					group[x] = group[y];
				}else{
					group[y] = group[x];
				}

			}
			else if(group[x] != group[y]){
				int r = group[x];
				int g = group[y];
				FOR(n)if(group[i] == g)group[i] = r;
			}
		}
		// FOR(n)cout<<group[i]+1<<" ";
		// cout<<endl;
	}
	int s = -1;
	FOR(n){
		if(group[i]!=-1 && s==-1 )
			s = i;
		else{
			if(group[i] != s){
				int k = group[i];
				for(int j=0;j<n;j++)if(group[j] == k){ group[j] = s; }
				group[i] = s;
				newroads.PB({s,i});
			}
		}
	}
	cout<<newroads.size()<<endl;
	for(auto x:newroads){
		cout<<x.F+1<<" "<<x.S+1<<endl;
	}
	cout<<endl;
}