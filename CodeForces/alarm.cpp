#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
                                // freopen("input.txt","r",stdin);
  int t;
  cin>>t;
  while(t--){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if(b>=a){
      cout<<b<<endl;
      continue;
    }else{
      if(c<=d){
        cout<<-1<<endl;
        continue;
      }else{
        int e = c-d;
        float j=a-b;
        ll u = ceil(j/e);
        ll r = b+u*(c);
        cout<<r<<endl;
        
      }
    }
  }
}
