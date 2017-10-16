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

    vector<int> exs, numDel;
    vector<string> subs, doneSubs;

    int num,mini,sz,k=0;
    string s;
    for(int i=0;i<n;i++){
        cin>>num;
        if(num>0){
            cin>>s;
            exs.push_back(num);
            subs.push_back(s);
        }else{
            mini=*min_element(exs.begin(), exs.end());
            while(exs.back()!=mini){
                k++;
                exs.pop_back();
                subs.pop_back();
            }
            doneSubs.push_back(subs.back());
            numDel.push_back(k);
            k=0;
            exs.pop_back();
            subs.pop_back();
        }
    }
    sz=doneSubs.size();
    for(int i=0;i<sz;i++){
        cout<<numDel[i]<<' '<<doneSubs[i]<<endl;
    }


    return 0;
}
