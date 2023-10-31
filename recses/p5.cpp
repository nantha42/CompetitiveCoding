#include<bits/stdc++.h>
#define FOR(n) for(int i=0;i<n;++i)
#define FOR1(n) for(int i=1;i<n;++i)
#define ll long long 
#define vint vector<int>
#define vlong vector<long long>
#define vstr vector<string>
#define vvin vector<vector<int>>
#define PB push_back
#define nl 

using namespace std;

bool ISPRIME(long long n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return false;
    } 
    return true; 
}
bool search(vint &app,int x,int k){
    int l = 0,r = app.size()-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(app[mid]>(x+k))
            r = mid-1;
        else if(app[mid]<(x-k))
            l = mid+1;
        else if (app[mid]>=(x-k) && app[mid]<=(x+k)){
            app.erase(app.begin()+mid);
            return true;
        }
    }
    return false;
}
int main(){
    int t;
    // freopen("input.txt","r",stdin);
    cin>>t;
    if(t==1 or t>3){
        int i = t;
        int j;
        int u;
        if(t%2 == 0){
            u = t/2; j = u;
            while(i>u){
                cout<<j<<" "<<i<<" ";
                i--;
                j--;
            }
            cout<<endl;
        }
        else{
            u = t/2+1; 
            j=u-1;
            while(i>u){
                cout<<i<<" "<<j<<" ";
                i--;
                j--;
            }
        cout<<u<<endl;
        }
    }
    else
    cout<<"NO SOLUTION"<<endl;
}