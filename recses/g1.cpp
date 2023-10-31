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
void fillit(vector<string> &strs,int i,int j,int n,int m){
	strs[i][j] = '#';
	// FOR(n)cout<<strs[i]<<endl;
	// cout<<endl;
	if(i+1 < n && strs[i+1][j] == '.')	
		fillit(strs,i+1,j,n,m);
	if(i-1 >= 0 && strs[i-1][j] == '.')	
		fillit(strs,i-1,j,n,m);
	if(j-1 >= 0 && strs[i][j-1] == '.')	
		fillit(strs,i,j-1,n,m);
	if(j+1 < m && strs[i][j+1] == '.')	
		fillit(strs,i,j+1,n,m);
}
int main(){
	int n,m;
	// freopen("input.txt","r",stdin);
	cin>>n>>m;
	vector<string> strs;
	FOR(n){
		string x;cin>>x;
		while(x.size()<m)
			x = x+ ".";
		
		strs.PB(x);
	}
	int areas = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(strs[i][j]=='.'){
				areas++;
				fillit(strs,i,j,n,m);
				// FOR(n)cout<<strs[i]<<endl;
				// cout<<endl;
			}
		}
	}
	// FOR(n)cout<<strs[i]<<endl;
	cout<<areas<<endl;
	
}