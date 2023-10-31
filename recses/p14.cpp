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
int free(int s,int t){
	if(s*t == 2)return 3;
	else if(s*t == 3)return 2;
	else return 1;
}
void move(int n,int s,int t,vector<vector<int>> &steps){
	if(n==1 ){
		// cout<<s<<" "<<t<<endl;
		steps.PB(vector<int>{s,t});
	}else{
		int g = free(s,t);
		move(n-1,s,g,steps);
		// cout<<s<<" "<<t<<endl;
		steps.PB(vector<int>{s,t});
		move(n-1,g,t,steps);
	}
}
int main(){
	int t;
	// freopen("input.txt","r",stdin);
	cin>>t;
	vector<vector<int>> steps;
	move(t,1,3,steps);
	cout<<steps.size()<<endl;
	for(auto x:steps){
		cout<<x[0]<<" "<<x[1]<<endl;
	}

}