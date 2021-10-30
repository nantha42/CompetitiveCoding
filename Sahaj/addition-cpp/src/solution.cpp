#include<bits/stdc++.h>
using namespace std;
string findp(string s,string prefix, string suffix){

	string ss;
	int pcount = 0;
	int scount  =0;
	int ps = prefix.size();
	int sus = suffix.size();
	int si=0,sj=0;
	int pi=0,pj=0;

	for(int i=0;i<s.size();i++){
		if(prefix[prefix.size()-i-1]==s[0]){
			int count = 1,j=0;
			for(j = 0;j<=i;j++ ){
				if(s[j] == prefix[ps-i-1 + j ])
					count++;
				else break;
			}
			if(count>pcount){
				pcount = count;
				pi = ps-i-1;
				pj = ps-i-1+(j-1);
			}
			// if(j>i) pcount = max(pcount,count);

		}
		if(suffix[0] == s[i]){
			int count = 0,j=0;
			for(j=0;j<s.size();j++){
				if(suffix[j]==s[i+j]){
					cout<<suffix[j]<<" "<<s[i+j]<<endl;
					count++;
				}
				else break;
			}
			if(count>scount){
				scount = max(scount,count);
				si = 0;
				sj = j-1;
			}
			
		}
	}
	cout<<pi<<" "<<pj<<" "<<si<<" "<<sj<<endl;
	string ans = prefix.substr(pi,pj-pi+1) + suffix.substr(si,sj-si+1);
	return ans;
}
int main(){
	string s = "nothing";
	string p = "gurno";
	string su = "ingenious";

	cout<<findp(s,p,su)<<endl;

}
