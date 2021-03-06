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
#define sortit(a)  sort(a.begin(),a.end())
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
	int n,m;
	cin>>n>>m;
	vector<bool> used(n,false);
	vint prics(m,0);
	int ar[2];
	set<array<int,2>> ticks;
	FOR(n){
		int a;
		cin>>a;
		ticks.insert({a,i});
	}
	// for(auto it:ticks)
	// 	cout<<(it)[0]<<" "<<(it)[1]<<endl;
	FOR(m)	{
		int a;
		cin>>a;
		auto it = ticks.lower_bound({a,0});
		if(ticks.empty()){
			cout<<-1<<endl;
		}else{
			if(it == ticks.begin()){
				if((*it)[0]> a){
					cout<<-1<<endl;
				}else{
					cout<<(*it)[0]<<endl;
					ticks.erase(it);
				}
			}else if(it == ticks.end()){
				it--;
				cout<<(*it)[0]<<endl;
				ticks.erase(it);
			}else {
					
				if((*it)[0] > a){
					do{
						it--;
						if((*it)[0]<=a){break;}
					}while(it!=ticks.begin());
				}
				cout<<(*it)[0]<<endl;
				ticks.erase(it);
			}
		}
	}	
}