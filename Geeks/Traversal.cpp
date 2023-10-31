
#include<iostream>
using namespace std;

void bfs(int s, vector<int> adj[], bool vis[], int N)
{
    // Your code her
  queue<int> qu;
  qu.push(s);
  while(!qu.empty()){
    int j =qu.front();
    qu.pop();
    vis[j] = true;
    cout<<j<<" ";
    for(int i=0;i<adj[j].length;i++){
      if(vis[adj[j][i]]==false){
	vis[adj[j][i]] = true;
	qu.push(adj[j][i]);
      }
    }
  }
    
}
int main(){

}
