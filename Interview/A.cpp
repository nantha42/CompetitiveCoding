#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    string s;
    cin>>s;
    vector<string> subs;
    string a="";
    int mx=0;
    string ans="";
    for(int i=0;i<s.size();i++){
       if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u')
           a+=s[i];
       else{
           if(a.size()>mx){
                mx = a.size();
                subs.erase(subs.begin(),subs.end());
                subs.push_back(a);
           }else if(a.size()==mx){
                subs.push_back(a);
            }
           a="";
       }
    }    
   for(auto x:subs)
       cout<<x<<" ";

}
