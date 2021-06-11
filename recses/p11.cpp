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
void swap(int &a,int &b){
	int t = a;
	a = b;
	b = t;
}
int main(){
	int t;
	// freopen("input.txt","r",stdin);
	cin>>t;
        while(t--){
		ll x,y;
		cin>>x>>y;
		
		if(x == y && x%3== 0 ){
			cout<<"YES"<<endl;
		}else if( 2*x == y || x== 2*y){
			cout<<"YES"<<endl;
		}else if(x>3 && y>3){
			if(x < y)swap(x,y);	
			int m = x-y;
			int a = y-m;
			a = a/3;
			int b = (x-a)/2;
			if(b*2 + a == x && b + 2*a == y && a>=0 && b>=0){
				cout<<"YES"<<endl;
			}else cout<<"NO"<<endl;

		}else{
			cout<<"NO"<<endl;
		}
	}	
}