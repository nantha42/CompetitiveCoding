
#include <bits/stdc++.h> 
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int v,e;
	    cin>>v>>e;
	    int mat[v][v] = {-1};
	    int count[v];
        memset(count,0,sizeof count);
	    memset(mat,-1,sizeof mat);
	    while(e--){
	        int s,p;
	        cin>>s>>p;
	        mat[s][count[s]] = p;
	        mat[p][count[p]] = s;
	        count[s]++;
	        count[p]++;
	    }
	    for(int i=0;i<v;i++){
	        cout<<i;
	        for(int j=0;j<v;j++)
	        {
                if(mat[i][j]>-1){
                    cout<<"-> "<<mat[i][j];
                }
	        }cout<<endl;
	    }
	}
	return 0;
}
