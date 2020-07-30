#include<bits/stdc++.h>
using namespace std;
int remaining(vector<int>&arr){
	int c=0;
	for(int x:arr)
		if(x>0)c++;
	return c;
}
int main(){
	// freopen("input.txt","r",stdin);
	int t;
	int x;
	cin>>t;
	while(t--){
		cin>>x;
		vector<int> arr(x);
		for(int i=0;i<x;i++){
			cin>>arr[i];
		}
		int p = x-1;
		while(p>0 && arr[p-1]>=arr[p])p--;
		while(p>0 && arr[p-1]<=arr[p])p--;
		cout<<p<<endl;
	}
}