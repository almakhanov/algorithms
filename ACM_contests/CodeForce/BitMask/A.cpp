#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){

    int n,k=0;
    cin>>n;
    int m=n;

    while(n>0){
        k++;
        n/=10;
    }

    int que=0;
    for(int i=0;i<k;i++){
        que+=pow(2,i);
    }
    string s;
    while(m>0){
        if(m%10==7) s+="1"; else s+="0";
        m/=10;
    }

    int c=0;
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=(s[i]-48)*pow(2,i);
    }

    cout<<que+sum;



    return 0;
}
