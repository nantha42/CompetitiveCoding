#include<bits/stdc++.h>
using namespace std;
int main(){
   // freopen("input.txt","r",stdin);
   int t;
   cin>>t;

  while(t--){
    string s;
    cin>>s;
    
    vector<char> st;


    int maxcount = 0;
    int curcount = 0; 
    
    for(auto x:s){
      
      if(x=='[')
        st.push_back('[');

      else if(x==']'){
        if(!st.empty() && st[st.size()-1]=='['){
          st.pop_back();
          curcount += 2;
          maxcount = max(maxcount,curcount);
        }else if(!st.empty()){
          st.clear();
          curcount = 0;
          maxcount = max(maxcount,curcount);
        }else{
          curcount = 0;
        }
      }
    }
    cout<<maxcount<<endl;

  }
  return 0;
}