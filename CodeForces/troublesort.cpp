#include<bits/stdc++.h>
#define ll long long
using namespace std;

/*bool space(vector<vector<int> > arr){
	int s = arr[0].size();
	for(int i=0;i<s*2;i++){
		for(int j=0;j<s-1;j++){
			if(arr[1][j]!=arr[1][j+1]){
				if(arr[0][j]>arr[0][j+1]){
					cout<<arr[0][j]<<" "<<arr[0][j+1]<<endl;
					int k = arr[0][j];
					arr[0][j] = arr[0][j+1];
					arr[0][j+1] = k;
					k = arr[1][j];
					arr[1][j] = arr[1][j+1];
					arr[1][j+1] = k;
				}
			}
		}
	}
	for(int i=0;i<s;i++)
		cout<<arr[0][i]<<" ";
	cout<<endl;
	for(int i=0;i<s-1;i++){
		if(arr[0][i]>arr[0][i+1]){
			return false;
		}
	}
	return true;
}
*/

bool space(vector<vector<int> > arr){
	int o=0,z=0;
	for(int i=0;i<arr[1].size();i++){
		if(arr[1][i]==1)
			o++;
		else
			z++;
	}
	if(o==0 || z==0)
		return false;
	return true;
}
int main(){
	freopen("input.txt","r",stdin);
	
	int n;
	cin>>n;
	while(n--){
		int a;
		cin>>a;
		vector<vector<int>> mat(2);
		int q;
		for(int i=0;i<a;i++){
			cin>>q;
			mat[0].push_back(q);
		}
		for(int i=0;i<a;i++){
			cin>>q;
			mat[1].push_back(q);
		}
		if(space(mat))
			cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}

	
	
}