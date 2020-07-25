#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){

    int n,q,data;
    int size = 1;
    cin>>n>>q;
    std:vector<int> arr[n];
//    std:vector<int> index;

    for(int i=0;i<n;i++)
    {
        cin>>size;
        for(int j = 0; j<size; j++)
        {
            cin>>data;
            arr[i].push_back(data);
        }
    }
    int r,s;
    for(int i = 0; i< q; i++)
    {
        cin >> r >>s;
        cout<<arr[r][s]<<endl;
    }

}