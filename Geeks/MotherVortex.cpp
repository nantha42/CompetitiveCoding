#include<iostream>
#include<vector>
#include<list>
#include <bits/stdc++.h>
#include<iterator>
using namespace std;

class Graph{
   int V;
  list<int> *adj;
  void DFSUtil(int v,vector<bool>  &visited){
    visited[v] = true;
    list<int>::iterator i;
    for(i = adj[v].begin();i!=adj[v].end();i++){
      if(!visited[*i]){
	DFSUtil(*i,visited);
      }
    }
  }
public:
  Graph(int v){
    this->V = v;
    adj = new list<int>[V];
  }
  void addEdge(int v,int w){
    adj[v].push_back(w);
  }
  void findMother(){
    vector<bool> visited(V,false);
  int v;
  for(int i=0;i<V;i++){
    if(visited[i]== false){
      DFSUtil(i,visited);
      v = i;
    }
  }

  fill(visited.begin(),visited.end(),false);
  DFSUtil(v,visited);
  
  for(int i=0;i<v;i++){
    if(visited[i]==false){
      cout<<"No Mother vortex";
      return;
    }
  }
  cout<<"Mother vortex"<<v;
  }
  
};
 

  int main(){
    
    Graph g(7);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    g.addEdge(5, 6); 
    g.addEdge(5, 2); 
    g.addEdge(6, 0);
    g.findMother();
    

    list<int> adj;
    adj.push_back(3);
    cout<<"hello"<<adj.front();
    return 0;
  }
