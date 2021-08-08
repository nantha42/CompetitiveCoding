
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	vector<long long> arr;
	arr.push_back(1);
	while(t--){
		long long x;
		cin>>x;
		if(arr.size()>x)cout<<arr[x]<<endl;
		else{
			for(int i=arr.size();i<x;i++){
				arr.push_back( ((i+1)*arr[i-1])%((long long)1e9+7) );
			}
			cout<<arr[x-1]<<endl;
		}
		
	}
	

}

