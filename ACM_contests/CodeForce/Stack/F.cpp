#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <stack>

using namespace std;

int main(){
    string s;
    cin>>s;
    int k=0, pos=0;
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(st.size()>0 && s[i]==')'){
                st.pop();
                pos+=2;
            }
        if(s[i]=='(') st.push(s[i]);

    }
    cout<<pos;

    return 0;
}
