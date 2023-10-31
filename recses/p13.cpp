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
int main(){
	int t;
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	cin>>t;
	FOR(pow(2,t)){
		int x = i;
		string s = "";
		int a = x%2;
		x >>= 1;
		if(x==0){ if(a)s += "1"; else s+= "0";}
		int b = -1;
		while(x>0){
			b = x & 1;
			if(a^b) s= '1' + s; else s= '0' + s;
			a = b;
			x >>=1;
		}
		if(b!=-1)s = (b?'1':'0') + s;
		
		if(s.size()<t){
			int k = s.size();
			FOR(t-k){
				s = '0' + s;
			}
		}
		cout<<s<<endl;
	}


}