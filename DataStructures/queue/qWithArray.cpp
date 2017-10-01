#include <iostream>

using namespace std;

class My_Queue{
    int a[1000000];
    int sz = 0;
    int start = 0;
  public:
    void push (int num){
        a[sz] = num;
        sz++;
    }

    int len (){
        return sz-start;
    }

    int first (){
        return a[start];
    }

    void pop (){
        start++;
    }
};
