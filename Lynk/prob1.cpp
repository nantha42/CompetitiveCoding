#include<bits/stdc++.h>
using namespace std;
int main(){
   // freopen("input.txt","r",stdin);
   int t;
   cin>>t;

  while(t--){
    int k,n;
    cin>>k>>n;
    vector<int> pp(n,0);
     
    for(int i=0;i<n;i++)
      cin>>pp[i];
     
    sort(pp.begin(),pp.end());
    cout<<pp[k-1]<<endl;
  }
  return 0;
}