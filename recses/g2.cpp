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
int n,m;
bool findpath(vector<vector<char>> &arr,int x,int y,string &path){
	if(arr[x][y] == 'B')
		return true; 
	arr[x][y] = 't';//taken
	bool found = false;
	if(x+1<n &&  (arr[x+1][y] ==  '.' || arr[x+1][y] ==  'B')) {
		found = findpath(arr,x+1,y,path);
		if(found)
			path += 'D';
	}
	if(!found && x-1 >=0 && (arr[x-1][y] == '.' || arr[x-1][y] ==  'B')){
		found = findpath(arr,x-1,y,path);
		if(found)
			path += 'U';
	}
	if(!found && y-1 >=0 && (arr[x][y-1] == '.' || arr[x][y-1] ==  'B')){
		found = findpath(arr,x,y-1,path);
		if(found)
			path += 'L';
		}
	if(!found && y+1 < m && (arr[x][y+1] == '.' || arr[x][y-1] ==  'B')){
		found = findpath(arr,x,y+1,path);
		if(found)
			path += 'R';
		}
	if(found)
		return true;
		
	arr[x][y] = '.';//taken
	return false;

}
int main(){
	
	// freopen("input.txt","r",stdin);
	cin>>n>>m;
	vector<vector<char>> arr;
	int values[n][m];
	// # 0  . 1 A 2 B 3
	int ax,ay;
	int bx,by;

	FOR(n){
		vector<char> rs(m,0);
		for(int j=0;j<m;j++){
			values[i][j] = 0;
			cin>>rs[j];
			if(rs[j] == 'A'){
				ax = i;
				ay = j;}
		}
		arr.PB(rs);
	}
	string path="";	
	// findpath(arr,ax,ay,path);
	// memset(values, sizeof values, 0);
	queue<pair<int,int>> Q; 	
	Q.push({ax,ay});
	if(path== "")
		cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		cout<<path.size()<<endl;
		reverse(path.begin(),path.end());
		cout<<path<<endl;
	}

}