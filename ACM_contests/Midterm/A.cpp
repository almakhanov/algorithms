#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cmath>
#include <ctime>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <stdlib.h>

using namespace std;
#define sz(a) (int)a.size()
#define vi vector <int>
#define pb push_back
#define mp make_pair
#define ll long long
#define sc scanf
#define pf printf
#define f first
#define s second

const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);

const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
// /////////////////////////////////////////////////////////////////////



int main(){
    int n;
    cin>>n;

    string A[n][2],B[n][2];
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>A[i][j];
        }
    }

    int l;
    string str;
    string strv="";
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){

            str = A[i][j];

            l=str.size();
            strv=str;
            int q=0;
            for(int c=l-1;c>=0;c--){
                strv[q]=str[c];
                q++;
            }
            B[i][j]=strv;
        }
    }

    int sum=0, S[n], num=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            l=B[i][j].size();
            str=B[i][j];
            for(int c=0;c<l;c++){
                num=num*10+(str[c]-48);
            }
            sum+=num;
            num=0;
        }
        S[i]=sum;
        sum=0;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        num=S[i];
        while(num>0){
            ans=ans*10+num%10;
            num/=10;
        }
        cout<<ans<<endl;
        ans=0;
    }

    return 0;
}
