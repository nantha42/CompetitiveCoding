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
        string s;
        cin>>s;
        string ans="";
        int i=0;
        if(s[0]=='?'){
            bool first=true;
            for(i=0;i<n;i++){
                if(s[i]=='R'){
                    first=true;
                    break;
                }else if(s[i]=='B'){
                    first = false;
                    break;
                }

            }
            if(i%2)
                first=!first;

            FR(j,i){
                if(first)
                    ans+='R';
                else
                    ans+='B';
                first = !first;
            }
            if(i<n)
                ans+=s[i];
            
            i++;
        }
        //?R???BR
        //BRBRBBR
        for(;i<n;i++){
            if(s[i]=='?'){
                char x = s[i-1]; 
                while(i<n && s[i]=='?'){
                    if(x=='R')
                        ans+='B';
                    else
                        ans+='R';
                    x=ans[i];
                    i++;
                }
                i--;
                
            }else{
                ans+=s[i];

            }
        }
        cout<<ans<<endl;

//        bool f= true;
//        //code
//
//        if(f)
//            cout<<"YES"<<endl;
//        else cout<<"NO"<<endl;

    }
	
}

