#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    string s;
    cin>>s;
    //aproch 1
    //find the max string len
    //print substring with maxlen # so no extra string
    //double traversal
    char ans[1000];
    int mx=0,c=0,j=0;
    for(int i=0;i<s.size();i++){
       if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u')
           c++;
       else{
           mx = max(mx,c);
          c=0;
       }
    }
    
    mx = max(mx,c);
    for(int i=0;i<s.size();i++){
       if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u'){
           ans[j]=s[i];
           j++;
       }
       else{
            if(j==mx)
            {   
                ans[j]='\0';
                cout<<ans<<" ";        
            }
            j=0;
            ans[0]='\0';
       }
    }
    if(j==mx)
        cout<<ans<<endl;
 
}
