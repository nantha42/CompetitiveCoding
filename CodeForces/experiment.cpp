#include<bits/stdc++.h>
using namespace std;
int main(){
	int x;
	int *y;
	x = 3;
	y = &x;
	vector<int*> v;
	v.push_back(y);
	cout<<*v[0]<<endl;

}