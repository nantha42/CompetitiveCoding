#include<bits/stdc++.h> 
using namespace std; 

bool seriescheck(int N, int digits) 
{ 
    int upperBound = int(pow(2, digits)+pow(2, digits - 1)-1); 
    int lowerBound = int(pow(2, digits)-1); 
    return (N >= lowerBound) && (N < upperBound); 
} 
bool powercheck(int N) 
{ 
    double number = log(N)/log(2); 
    int checker = int(number); 
    return number - checker == 0; 
} 
string solve(int N) 
{ 

    string numbers[N + 1]; 
    numbers[0] = ""; 

  

    int blocks = 0; 
    int displacement = 0; 
    for (int i = 1; i < N + 1; i++) { 
        if (powercheck(i + 1)) {
            blocks = blocks + 1; 
        } 
        if (seriescheck(i, blocks)) { 
            displacement = int(pow(2, blocks - 1)); 
            numbers[i] = "4" + numbers[i - displacement] + "4"; 
        } 
        else { 
            displacement = int(pow(2, blocks)); 
            numbers[i] = "5" + numbers[i - displacement] + "5"; 
        } 
    } 
    return numbers[N]; 
} 
int main() 
{ 
    // freopen("input.txt","r",stdin);
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        string pure = solve(n); 
        cout << pure << endl; 
    }
} 