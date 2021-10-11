#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    map<int, int> um;
    cin>>n;
    int curr_sum = 0;
    int arr[n];

    // int count = 0;
    // for(int i=0;i<n;i++){
    //  cin>>arr[i++];
    //  arr[i-1] = ((arr[i-1]&1)?-1:1);
    // }
    // map<int,int> mp;
    // for(int i=0;i<n;i++){    
    //  count += arr[i];
    //  mp[count]++;
    // }
    // count = 0;
    // for(auto it=mp.begin();it!=mp.end();it++){
    //  if(it->second>1)
    //  count += (it->second*(it->second-1))/2;
    // }
    // if(mp.find(0)!=mp.end())
    //  count+=mp[0];
    // cout<<count<<endl;


    for (int i = 0; i < n; i++) {
        cin>>arr[i];
        if(arr[i]%2==0)arr[i]=0;else arr[i] = 1;
        curr_sum += (arr[i] == 0) ? -1 : 1;
        cout<<curr_sum<<" +1"<<endl;
        um[curr_sum]++;
    }

    int count = 0;
    for (auto itr = um.begin(); itr != um.end(); itr++) {
        cout<<itr->second<<endl;
        if (itr->second > 1){
             int t = (int)itr->second;
            count += t*(t-1)/2;
         }
    }

     if (um[0] >0)
      count += um[0];

    cout<<count<<endl;
    return count;

}
