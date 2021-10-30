#include<bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

vector<int> minimalMoves(vector<vector<int>> cameraPositions) {
    vector<int> mm;
    int width = cameraPositions[0].size() - 1;
    int c = width + 1;
    int pos = cameraPositions.size()-1;
    while (pos > 0) {
        if (c == 0) {
            c = width - 1;
            if (mm.size() == 0) {
                return mm;
            }
        }
        else {
            c--;
        }
        if (cameraPositions[pos-1][c] == 1) {
            mm.push_back(0);
        }
        else {
            mm.push_back(1);
            pos--;
        }
    }
    return mm;
}

int main() {
    freopen("input.txt","r",stdin);
    vector<vector<int>> cameraPositions;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        vector<int> a;
        for (int j=0;j<m;j++) {
            int q;
            cin>>q;
            a.push_back(q);
        }
        cameraPositions.push_back(a);
        cout << endl;
    }
    vector<int> p = minimalMoves(cameraPositions);
    for (int i = 0; i < p.size(); i++) {
        cout << p[i]<<" ";
    }
}