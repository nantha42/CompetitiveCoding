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
	string s;
	// freopen("input.txt","r",stdin);
	cin>>s;
	map<char,int> mp;
	map<char,string>wo;
	FOR(s.size()){
		mp[s[i]]++;
		wo[s[i]] += s[i];
		// if(wo[s[i]] == ""){
		// 	wo[s[i]]+= s[i];
		// }
	}
	bool f = false;
	char c='0';
	for(auto x:mp){
		if(x.second%2 == 1){
			if(!f){
				f = true;
				c = x.first;
			}else{
				cout<<"NO SOLUTION"<<endl;
				return 0;
	
			}
		}
	}
	string formed="";
	if(c != '0'){
		while(mp[c]){
			formed += c;
			mp[c]--;
		}
	}
	for(auto x:mp){
		if(x.second > 0){
			string half = wo[x.first].substr(0,x.second/2);
			formed = half + formed + half;
			// FOR(x.second/2){
			// 	formed = x.first+formed;
			// 	formed = formed + x.first;
			// }
		}
	}
	cout<<formed<<endl;	
}