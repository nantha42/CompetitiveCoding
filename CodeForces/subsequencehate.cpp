#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;		
		int n = s.size();
		char cur = s[0];
		int start=-1,end=-1;
		int count;
		int temp = 0;
		for(int i=1;i<n;i++){
			if(s[i]!=cur){
				cur = s[i];
				if(start==-1)
					start = i;
				else{
					for(int j=start;j<i;j++)
						temp++;
					start = -1;
				}
			}
		}
		// cout<<temp<<endl;

		count= temp;
		temp = 1;
		if(s[0]=='0')
			cur='1';
		else cur='0';
		start = -1;
		for(int i=1;i<n;i++){
			if(s[i]!=cur){
				cur = s[i];
				if(start==-1)
					start = i;
				else{
					for(int j=start;j<i;j++)
						temp++;
					start = -1;
				}
			}
		}
		start = -1;
		// cout<<temp<<endl;
		count = min(count,temp);
		cur = s[n-1];
		temp=0;
		for(int i=n-2;i>=0;i--){
			if(s[i]!=cur){
				cur = s[i];
				if(start==-1)
					start = i;
				else{
					for(int j=start;j>i;j--)
						temp++;
					start = -1;
				}
			}
		}
		start = -1;
		// cout<<temp<<endl;
		count = min(count,temp);
		temp = 1;
		if(s[n-1]=='0')
			cur='1';
		else cur='0';
		
		for(int i=n-2;i>=0;i--){
			if(s[i]!=cur){
				cur = s[i];
				if(start==-1)
					start = i;
				else{
					for(int j=start;j>i;j--)
						temp++;
					start = -1;
				}
			}
		}
		// cout<<temp<<endl;
		count = min(count,temp);
		cout<<count<<endl;
	}
}