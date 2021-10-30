#include "cinderella.h"
#include <vector>
#include<bits/stdc++.h>
#define FOR(r,a,inc) for(int i=r;i<a;i+=inc)
using namespace std;
void moveright(vector<vector<int>>&cameraPositions){
	for(int j=0;j<cameraPositions.size();j++){
		for(int i=0;i<cameraPositions[j].size();i++)
			if(cameraPositions[j][i]==1){
				if(i==cameraPositions[j].size()-1){
					cameraPositions[j][i]=0;cameraPositions[j][0] = 1;
					break;
				}
				else{
					cameraPositions[j][i]=0;cameraPositions[j][i+1]=1;
					break;
				}
		}
	}
}
void moveleft(vector<vector<int>>&cameraPositions){
	for(auto &a:cameraPositions){
		for(int i=0;i<a.size();i++)
			if(a[i]==1){
				if(i==0){a[0]=0;a[a.size()-1] = 1;break;}
				else{a[i]=0;a[i-1]=1;break;}
			}
	}
}
vector<int> moves;
bool findit(vector<vector<int>> &cameraPositions,vector<int> minimalMoves,int j){
	if(j==0)
		return true;
	else{
		moveright(cameraPositions);
		if(cameraPositions[j-1][0]==1){
			moveleft(cameraPositions);
			return false;
		}else{
			moves.push_back(1);
			bool r = findit(cameraPositions,minimalMoves,j-1);

			if(r==false)
			{
				moves.pop_back();
				moveright(cameraPositions);
				if(cameraPositions[j][0]==1){
					moveleft(cameraPositions);
					return false;
				}
				else{
					moves.push_back(0);
					if(findit(cameraPositions,minimalMoves,j)==false){
						moves.pop_back();
						return false;
					}else{
						return true;
					}
				}
				moves.push_back(0);

			}else{
				return true;
			}
		}
	}
	return false;
}

vector<int> minimalMoves(vector<vector<int>> cameraPositions){
   vector<int> minimalMoves;
   int j = cameraPositions.size()-1;
   findit(cameraPositions,minimalMoves,j);
   return moves;
}
int main(){
	freopen("input.txt","r",stdin);
	int m,n;
	cin>>m>>n;
	vector<vector<int>> a;
	for(int i=0;i<m;i++){
		vector<int> q;
		for(int j=0;j<n;j++){
			int r;cin>>r;
			q.push_back(r);
		}
		a.push_back(q);
	}
	
	return 0;
}