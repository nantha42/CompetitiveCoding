#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Pos{
public:
  int x;
  int y;
  Pos(int a,int b){
    x = a;
    y = b;
  }
  Pos(){
    x = 0;
    y = 0;
  }
};


bool find(map<Pos,vector<Pos> > &gg,int x,int y,int px,int py){
  for(int i=0;i<gg.size();i++){
    vector<int> a = gg[i];
    if(a[0] == x && a[1] == y){
      if(a[2] == px && a[3] == py)
        return true;
    }
      if(a[2] == x && a[3] == y){
        if(a[0] == px && a[1] == py)
          return true;
    }
      
  }
    vector<int> temp{px,py,x,y};
    gg.push_back(temp);
    return false;
  
}

int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    map<Pos,vector<Pos>> g;
    cin>>s;
    int x=0,y=0;
    int count= 0;
    for(int i=0;i<s.length();i++){
      int px = x;
      int py = y;
      if(s[i]=='E')
        x++;
      else if(s[i]=='N')
        y--;
      else if(s[i] == 'S')
        y++;
      else if(s[i] == 'W')
        x--;

      if(find(g, x, y, px, py)){
        count+=1;
      }else{
        count+=5;
      }
    }
    cout<<count<<endl;
  }
  
}
