#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
   ll n;
   cin>>n;
   int i=1;
   for(int i=1;i<=n;i++){
        int l=0;
        int a = n;
        cout<<i<<" ";
        l=n;
        for(int j=1;j<i;j++){
                cout<<l+(i-j-(j-1))<<" ";
            l+=a;
            a--;
        }
        cout<<endl;
   }

}
