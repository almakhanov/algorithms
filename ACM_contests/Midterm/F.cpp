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
    string str, res, tmp;
    int sz, q=0, A[n],k=0;
    bool isOk=true, isCor=false;
    string s[n];

    int sc=1, sz2=0;


    for(int i=0; i<n; i++) cin>>s[i];

    for(int i=0;i<n;i++){
        sz=s[i].size();
        for(int j=sz-1;j>sz/2;j--){
            if(s[i][j]!=s[i][q]){
                isOk=false;
                break;
            }
            q++;
        }
        q=0;
        if(isOk){
            A[i]=0;
        }
        sc=1;
        while(!isOk){

            if(!isCor){
                for(int o=sz-1;o>sz-1-sc;o--){
                    tmp+=s[i][o];
                }
                for(int o=0;o<sz;o++){
                    tmp+=s[i][o];
                }
                //cout<<tmp<<' ';
                isCor=true;
                q=0;
                sz2 = tmp.size();

                for(int o=sz2-1;o>sz2/2;o--){
                    if(tmp[o]!=tmp[q]){
                        cout<<"not Cororor";
                        isCor=false;
                        break;
                    }
                    q++;
                }
                if(isCor){
                    A[i]=sc;
                }
            }

            tmp="";
            if(!isCor){
                for(int o=0;o<sz;o++){
                    tmp+=s[i][o];
                }
                for(int o=sc-1; o>=0; o++){
                    tmp+=s[i][o];
                }
                //cout<<tmp<<' | ';
                isCor=true;
                sz2 = tmp.size();
                q=0;
                for(int o=sz2-1;o>sz2/2+1;o--){
                    if(tmp[o]!=tmp[q]){
                        isCor=false;
                        break;
                    }
                    q++;
                }
                if(isCor){
                    A[i]=sc;
                }

            }

            //if(isCor==true) cout<<"go";

            if(isCor) isOk=true;
            q=0;
            tmp="";
            sc++;
        }




    }


    for(int i=0; i<n; i++){
        cout<<"Case "<<i+1<<" : "<<A[i]<<' '<<endl;
    }



    return 0;
}
