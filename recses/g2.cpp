#include<bits/stdc++.h>
#define FOR(n) for(int i=0;i<n;++i)
#define FOR1(n) for(int i=1;i<n;++i)
#define ll long long 
#define vint vector<int>
#define vlong vector<long long>
#define vstr vector<string>
#define vvin vector<vector<int>>
#define PB push_back
#define F first 
#define S second 
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

int main(){
	
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
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
				ay = j;
				values[i][j] = 1;
				}
			else if(rs[j] == 'B'){
				bx = i;
				by = j;}
	}
		arr.PB(rs);
	}
	string path="";	
	queue<pair<int,int>> Q; 	
	Q.push(pair<int,int>{ax,ay});
	bool found = false;
	do{
		pair<int,int> p = Q.front();Q.pop();
		int x= p.F,y =p.S;
		if(x == bx && y == by){
			 found = true;break;}

		if(x+1<n &&  (arr[x+1][y] ==  '.' || arr[x+1][y] ==  'B') && values[x+1][y]==0 ) {
			values[x+1][y ] = values[x][y]+1;
			Q.push(pair<int,int>{x+1,y});
		}
		if( x-1 >=0 && (arr[x-1][y] == '.' || arr[x-1][y] ==  'B')&&values[x-1][y]== 0){
			values[x-1][y ] = values[x][y]+1;
			Q.push(pair<int,int>{x-1,y});
		}
		if(y-1 >=0 && (arr[x][y-1] == '.' || arr[x][y-1] ==  'B')&&values[x][y-1]== 0 ){
			values[x][y-1 ] = values[x][y]+1;
			Q.push(pair<int,int>{x,y-1});
		}
		if(y+1 < m && (arr[x][y+1] == '.' || arr[x][y+1] ==  'B') && values[x][y+1]== 0){
			values[x][y+1] = values[x][y]+1;
			Q.push(pair<int,int>{x,y+1});
		}
	}while(!Q.empty());
	if(found){
		int i = bx,j = by;
		bool rstart = false;
		do{
			// cout<<i<<" "<<j<<endl;
			// cout<<path<<endl;
			if(i==ax && j == ay) 
				break;
			if(i-1 >= 0 && values[i-1][j] == values[i][j]-1 ){
				i--;
				path += 'D';
			}
			else if(i+1 < n && values[i+1][j] == values[i][j]-1){
				i++;
				path += 'U';
			}
			else if(j-1 >= 0 && values[i][j-1] == values[i][j]-1){
				j--;
				path += 'R';
			}
			else if(j+1 < m && values[i][j+1] == values[i][j]-1){
				j++;
				path += 'L';
			}
		}while(!rstart);
	}
	
	if(path== "")
		cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		cout<<path.size()<<endl;
		reverse(path.begin(),path.end());
		cout<<path<<endl;
	}

}