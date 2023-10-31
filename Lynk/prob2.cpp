#include<bits/stdc++.h>
using namespace std;
int minvalue = INT_MAX;
int N;
void solve(vector<vector<int>> &arr,vector<vector<bool>> &v,int i,int j,int cursum){

	if(i== N-1 && j==N-1){
		minvalue = min(minvalue,cursum+arr[i][j]);
		return ;
	}
	else{ 
		v[i][j] = true;
		if(i<N-1 && v[i+1][j]==false)
			solve(arr,v,i+1,j,cursum+arr[i][j]);
			
		
		if(i>0 && v[i-1][j]==false)
			solve(arr,v,i-1,j,cursum+arr[i][j]);
		
		if(j<N-1 && v[i][j+1]==false)
			solve(arr,v,i,j+1,cursum+arr[i][j]);
		
		if(j>0 && v[i][j-1]==false)
			solve(arr,v,i,j-1,cursum+arr[i][j]);
		
		v[i][j] = false;
	}

}

int main()
{
	
	// freopen("input.txt","r",stdin);
	int t;
	cin>>t;
	string nums;
	getline(cin,nums);
	while(t--){
		getline(cin,nums);
		// cout<<nums<<endl;
		vector<int> arr;
		string temp="";
		for (auto x : nums) 
 	   { 
	       if (x == ' ') 
	       { 
	           
	       	   stringstream f(temp);
	       	   int q;
	       	   f>>q;
	           arr.push_back(q);
	           temp = ""; 
	       } 
	       else
	       { 
	           temp = temp + x; 
	       } 
 	   }  
 	   stringstream f(temp);
   	   int q;
   	   f>>q;
       arr.push_back(q);
       
       int n = sqrt(arr.size());
	   N = n;
	   vector<vector<int>> mat;
	   vector<vector<bool>> v;
       for(int i=0;i<n;i++){
       	vector<int> row;
		vector<bool> rowf(n,false);
		v.push_back(rowf);

       	for(int j=0;j<n;j++){
       		row.push_back(arr[i*n+j]);
       	}
       	mat.push_back(row);
       }

       solve(mat,v,0,0,0);
	   cout<<minvalue<<endl;
	}

}