#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("input.txt","r",stdin); 
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int arr1[n];
    memset(arr1,0,sizeof arr1);
    bool done[n];
    memset(done,0,sizeof done);
    for(int i=0;i<n;i++){
        if(!done[i]){
            int x= arr[i];
            int f= 1e9;
            int g = -1;
            int v = 1e9;
            for(int j=i+1;j<n;j++){
                if(arr[j] > x and arr[j] < f){
                    arr1[i] = arr[j];
                    if(g!=-1)
                        arr1[g] = 0;
                    g = j;
                    f = arr[j];
                }else if(f != 1e9){
                    if(arr[g] < arr[j] and arr[j] < v){
                       arr1[g] = arr[j]; 
                       v = arr[j];
                    }
                }
            }
          if(f!=1e9) 
              done[i] = true;
          if(g!=-1)
              done[g] = true;
        }
        
    }
    for(int i=0;i<n;i++)
        if(done[i])
            cout<<arr1[i]<<" ";
        else
            cout<<-1<<" ";

}
