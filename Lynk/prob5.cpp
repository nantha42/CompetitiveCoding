#include<bits/stdc++.h>
using namespace std;
bool comp(string &s,string &s2){
    if (s.size() == s2.size())return s < s2; else return s.size() < s2.size();
}

int main(){
    int t;
    freopen("input.txt","r",stdin);
    cin>>t;
    queue<string> q; 
    set<string> ans; 
  
    q.push("44"); 
    q.push("55"); 
    

    while(t--){
        int n;
        cin>>n;
        if(ans.size()<n){
            while (ans.size() < n) { 
      
                string temp = q.front(); 
                q.pop(); 
                ans.insert(temp); 
                q.push("4" + temp + "4"); 
                q.push("5" + temp + "5"); 
            }
            sort(ans.begin(), ans.end(), comp); 
            vector<string> temp(ans.begin(),ans.end());
            cout<<temp[n-1]<<endl;
        }
        else{
            vector<string> temp(ans.begin(),ans.end());
            cout<<temp[n-1]<<endl;
        }

    }
}
