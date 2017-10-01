#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int bSearch(vector<int> v, int a){
    int sz=v.size();
    int low=0;
    int high=sz-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(a==v[mid]){
            return mid;
        }else if(a>v[mid]){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}

int main(){

    int n,m,x;
    cin>>n>>m;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }


    int A[m];
    for(int i=0;i<m;i++)
    cin>>A[i];

    for(int i=0;i<m;i++){
        if(bSearch(v, A[i])==-1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }



    return 0;
}
