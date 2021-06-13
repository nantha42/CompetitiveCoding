#include<bits/stdc++.h>
#define FOR(n) for(int i=0;i<n;++i)
#define FOR1(n) for(int i=1;i<n;++i)
#define ll long long 
#define vint vector<int>
#define vlong vector<long long>
#define vstr vector<string>
#define vvin vector<vector<int>>
#define PB push_back
#define printarr(aa) FOR(aa.size())cout<<aa[i]<<" ";
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
int main(){
	int t;

	// freopen("input.txt","r",stdin);

	cin>>t;
	vint arr(t,0);
	ll as = 0,bs = 0;
	FOR(t){cin>>arr[i];as+= arr[i];}
	if(t == 1){ cout<<arr[0]<<endl;return 0;}
	sort(arr.begin(),arr.end());
	ll mini = 1e9;
	vint aa,bb;
	for(int i=1;i<pow(2,t-1);i++){
		int x = i;
		ll copy = as;
		bs = 0;
		int j = 0;
		while(x>0){
			if(x&1)
			{
				copy -= arr[j];
				bs+= arr[j];
			}
			x = x>>1;	
			j++;
		}
		if(mini > abs(copy-bs))	mini = abs(copy-bs);
	}
	cout<<mini<<endl;
	
}