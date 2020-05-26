#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
vector<int> get_distinct(vector<int> &x){
  set<int> dis;
  map<int,int> hashmap;
  for(int i=0;i<x.size();i++){
    dis.insert(x[i]);
    auto itr = hashmap.find(x[i]);
    if(itr!=hashmap.end()){
      itr->second = itr->second+1;
    }
    else{
      hashmap.insert(pair<int,int>(x[i],1));
    }
  }
  int max = 0;
  for(auto itr = hashmap.begin();itr!=hashmap.end();itr++){
    if(max<itr->second)
      max = itr->second;
  }
  vector<int> retu(dis.size());
  
  copy(dis.begin(),dis.end(),retu.begin());
  retu.push_back(max);
  return retu;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k,j;
    cin>>n>>k;
    vector<int> x(n);
    for(int i=0;i<n;i++){
      cin>>j;
      x[i] = j;
    }
    vector<int> dis = get_distinct(x);
    int maxi = dis[dis.size()-1];
    auto it = dis.end();
    // cout<<dis.size()<<endl;     
    it--;
    dis.erase(it);
    // cout<<dis.size()<<endl;
    
    if(dis.size()>k)
      cout<<-1<<endl;
    else{
      if(dis.size()==k){
        int q=0,w=0,a;
        for(a=0;a<n;a++)
          if(x[0]==dis[(a)%k])
            break;
        vector<int> res;
        while(q<n){
          // for(int j=0;j<dis.size();j++)
          //   cout<<dis[j]<<" ";
          if(x[q]==dis[a%k]){
            res.push_back(x[q]);
            
            q++;a++;
          }
          else{
            res.push_back(dis[a%k]);
            
            a++;
          }
        }
        cout<<res.size()<<endl;
        for(auto it=res.begin();it!=res.end();it++)
          cout<<*it<<" ";
        cout<<endl;

      }else if(dis.size()<k){
        
        while(dis.size()<k){
          dis.push_back(dis[dis.size()-1]+1);
        }
        int q=0,w=0,a;
        for(a=0;a<n;a++)
          if(x[0]==dis[(a)%k])
            break;
        vector<int> res;
        while(q<n){
          // for(int j=0;j<dis.size();j++)
          //   cout<<dis[j]<<" ";
          if(x[q]==dis[a%k]){
            res.push_back(x[q]);
            
            q++;a++;
          }
          else{
            res.push_back(dis[a%k]);
            
            a++;
          }
        }
        cout<<res.size()<<endl;
        for(auto it=res.begin();it!=res.end();it++)
          cout<<*it<<" ";
        cout<<endl;
      }
    }
  }
}
