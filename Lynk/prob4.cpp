#include<bits/stdc++.h>
using namespace std;
int solution(int n) 
{ 
	int play[n + 1];
	for(int j = 0; j < n + 1; j++) 
		play[j] = 0; 
	play[0] = 1; 
	for (int i=2; i<=n;i++) 
		play[i] += play[i - 2];
	for (int i=3; i<=n;i++) 
		
		play[i] += play[i - 3]; 

	for (int i=5; i<=n;i++) 
		play[i] += play[i - 5]; 

	return play[n]; 
} 


int main()
{
	// freopen("input.txt","r",stdin);
	int t;
	cin>>t;
	while(t--){
	int temp;
	vector<int>v;
	while(cin>>temp)
		v.push_back(temp);
	
	for(int i=0;i<v.size();i++)
	{
	   cout<<solution(v[i]);
	   cout<<endl;
	}
 	}

}