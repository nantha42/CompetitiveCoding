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
	vector<array<int,2>> times; 
    while(t--){
		int x,y;
		cin>>x>>y;
		times.PB({x,y});
	}	
	sortit(times);
	priority_queue<int,vector<int>, greater<int>> q;
	int maxcus = 0;
	FOR(times.size()){
		int y = times[i][1];
		int x = times[i][0];
		if(q.empty()){
			q.push(y);
		}else{
			while(!q.empty() && x > q.top()){
				q.pop();	
			}
			q.push(y);
			int s = q.size();
			maxcus  = max(maxcus,s);
		}
	}
	cout<<maxcus<<endl;	
}