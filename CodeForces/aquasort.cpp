#include<bits/stdc++.h>
#define FOR(n) for(int i=0;i<n;++i)
#define FOR1(n) for(int i=1;i<n;++i)
#define FR(i,n) for(int i=1;i<n;++i)
#define rng(a,b) for(int i=a;i<b;++i)
#define ll long long 
#define vint vector<int>
#define vlong vector<long long>
#define vstr vector<string>
#define vvin vector<vector<int>>
#define PB push_back
#define nl "\n"
#define F first
#define S second
#define __ << " " << 
#define ar array
#define sortit(x) sort(x.begin(),x.end())
#define umap unordered_map
using namespace std;
template <typename T>
void insert(vector<T> &vec, T x ){
	auto it = vec.lower_bound(x);
	vec.insert(it,x);
}
bool ISPRIME(long long n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0)
			return false;
	} 
	return true; 
}
/*
 * 3 2 1
 * r r r 
 * 2 3 1
 * l l r
 * 2 1 3
 * l r l
 * 3 3 2 2
 * 3 2 3 2
 * r l l r
 * 3 2 2 3
 * r l r l
 * 2 3
 * r l 
*
* */

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    #else
    #endif
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<array<int,2>> arr(n);
        FOR(n){
            cin>>arr[i][0];
            arr[i][1] = i;
        }
        sortit(arr);
        bool f = true;
        FR(i,n){

            if((arr[i][1]-i)%2!=0){
                if(i+1<n && (arr[i+1][1]-i+1)%2!=0 && arr[i][0]==arr[i+1][0]) 
                    i+=1;
                else
                f=false;
            }
        }
        if(f)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
	
}

