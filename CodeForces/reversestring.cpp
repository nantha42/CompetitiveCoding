#include<bits/stdc++.h>
#define FOR(n) for(int i=0;i<n;++i)
#define FOR1(n) for(int i=1;i<n;++i)
#define ll long long 
#define vint vector<int>
#define vlong vector<long long>
#define vstr vector<string>
#define vvin vector<vector<int>>
#define PB push_back
#define nl "\n"
#define F first
#define S second
#define sortit(x) sort(x.begin(),x.end())
using namespace std;
bool ISPRIME(long long n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return false;
    } 
    return true; 
}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    int t;cin>>t;
    while(t--){
        string s,x;
        cin>>s>>x;
        bool f = false;
        for(int i=0;i<s.size();i++){
            
            if(s[i] == x[0]){
                int j=1;
                queue<int> q;
                for(;j<x.size();j++){
                    if(i+j >= s.size() || s[i+j] != x[j])
                        break;
                    if(i+j-2 >=0 && s[i+j-2] == s[i+j])
                        q.push(j);
                }

                j--;
                int k=1;
                for(;k+j<x.size();k++){
                    if( i+j-k<0 || s[i+j-k]!=x[k+j])
                        break;
                }
                
                if(k+j==x.size()){
                   f = true; 
                }



                while(!q.empty()){
                    j = q.front();
                    q.pop();
                    j--;
                    int k=1;
                    for(;k+j<x.size();k++){
                        if( i+j-k<0 || s[i+j-k]!=x[k+j])
                            break;
                    }
                    
                    if(k+j==x.size()){
                 //       cout<<k<<" "<<j<<endl;
                       f = true; 
                    }
                }
             
            }
            if(f)
                break;
        }
        if(f)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
 
    }
}
