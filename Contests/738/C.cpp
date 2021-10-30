#include<bits/stdc++.h>
#define FOR(n) for(int i=0;i<n;++i)
#define FOR1(n) for(int i=1;i<n;++i)
#define FR(i,n) for(int i=0;i<n;++i)
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
        vector<int> arr(n);
        int one_way=-1;
        FOR(n){
            cin>>arr[i];
            if(i>0 && arr[i])
                if(arr[i-1]==0)
                    one_way = i-1;
        }
        bool f= true;
        //code
        if(arr[n-1]==0){
            FOR(n+1)
                cout<<i+1<<" ";
            cout<<endl;
        }else if(arr[0]==1){
            cout<<n+1<<" ";
            for(int i=0;i<n;i++)
                cout<<i+1<<" ";
            cout<<endl;
        }
        else{
            if(one_way!=-1){
                int i=0;
                for(;i<one_way;i++){
                   cout<<i+1<<" "; 
                }
                cout<<one_way+1<<" "<<n+1<<" ";
                for(i=one_way+1;i<n;i++)
                    cout<<i+1<<" ";
                cout<<endl;
            }else{
                cout<<-1<<endl;
            }

        }

//        if(f)
//            cout<<"YES"<<endl;
//        else cout<<"NO"<<endl;

    }
	
}

