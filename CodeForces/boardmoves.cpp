#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll get(ll s){
  int x=0,y=10;
  while(s>0){
    int t = s%10;
    s = s/10;
    x = max(x,t);
    y = min(y,t);
  }
  return x*y;
}
int main(){
  freopen("input.txt","r",stdin);
  int t;
  cin>>t;
  while(t--){
      int n,k;
      cin>>n>>k;
      ll s = n;
      for(int j=1;j<k;j++){
        ll u = get(s);
        if(u==0)
          break;
        s = s+ u;
      }
      cout<<s<<endl;

  }
  
}

