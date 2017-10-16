#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

int main(){

    string s;
    cin>> s;
    stack<char> st;
    int len=s.size();
    for(int i=0; i<len;i++){

        if(st.size()>0){
            if(s[i]==st.top()) {
                st.pop();
                continue;
            }
        }
            st.push(s[i]);
    }
    int sz=st.size();
    char a[sz];
    for(int i=0;i<sz;i++){
        a[i]=st.top();
        st.pop();
    }
    for(int i=sz-1; i>=0;i--){
        cout<<a[i];
    }



    return 0;
}
