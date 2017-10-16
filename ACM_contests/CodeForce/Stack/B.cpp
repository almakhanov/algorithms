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

    string s;
    stack<char> u, t;
    cin>>s;

    int sz=s.size();

    char C[sz];
    for(int i=0;i<sz;i++){
        C[i]=s[i];
    }
    sort(C, C+sz);

    int k=0;
    for(int i=0;i<sz;i++){
        if(s[i]==C[k]){
            u.push(s[i]);
            k++;
        }else{
            t.push(s[i]);
        }

    }
    int tsz=t.size();
    for(int i=0;i<tsz;i++){
        u.push(t.top());
        t.pop();
    }

    char A[sz];
    for(int i=0;i<sz;i++){
        A[i]=u.top();
        u.pop();
    }
    for(int i=sz-1;i>=0;i--){
        cout<<A[i];
    }





    return 0;
}
