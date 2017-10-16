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
int n;
deque<string> st;
deque<string> d;

void push(string s, int f){
    int sz=s.size();
    string str="";
    if(f==4){
        while(!st.empty()){
            st.pop_back();
        }
    }
    for(int i=f;i<sz;i++){
        if(s[i]=='/'){
            i++;
            st.pb(str);
            str="";
        }
        if(i==sz-1){
            str+=s[i];
            st.pb(str);
            return;
        }
        str+=s[i];
    }
}


int main(){

    cin>>n;

    string s[n];
    getline(cin,s[0]);
    for(int i=0; i<n;i++){
        getline(cin, s[i]);
    }

    for(int i=0;i<n;i++){
        if(s[i][0]=='p' && s[i][1]=='w' && s[i][2]=='d'){
            cout<<'/';
            int sz=st.size();
            if(sz==0) {
                cout<<endl;
                continue;
            }
            while(!d.empty()){
                d.pop_back();
            }
            for(int j=sz-1;j>=0;j--){

                if(sz>3 && st[j][0]=='.' && st[j][1]=='.' && st[j-1][0]=='.' && st[j-1][1]=='.' && st[j-2][0]!='.' && st[j-2][1]!='.' && st[j-3][0]=='.' && st[j-3][1]=='.'){
                    j--;
                    j--;
                    j--;
                    j--;
                    j--;
                    continue;
                }else if(sz>2 && st[j][0]=='.' && st[j][1]=='.' && st[j-1][0]=='.' && st[j-1][1]=='.' && st[j-2][0]=='.' && st[j-2][1]=='.'){
                    j--;
                    j--;
                    j--;
                    j--;
                    j--;
                    continue;
                }else if(sz>1 && st[j][0]=='.' && st[j][1]=='.' && st[j-1][0]=='.' && st[j-1][1]=='.'){
                    j--;
                    j--;
                    j--;
                    continue;
                }else if(st[j][0]=='.' && st[j][1]=='.'){
                    j--;
                    continue;
                }
                d.pb(st[j]);
            }
            int dsz=d.size();
            for(int o=dsz-1;o>=0;o--){
                cout<<d[o]<<'/';
            }
            cout<<endl;
        }else if(s[i][0]=='c' && s[i][1]=='d'){
            if(s[i][3]=='/'){
                push(s[i],4);
            }else{
                push(s[i],3);
            }
        }
    }

    return 0;
}
