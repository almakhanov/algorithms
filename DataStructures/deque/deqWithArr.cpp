#include <iostream>

using namespace std;

class My_Dequeue{
    int a[1000000];
    int sz = 500000;
    int start = 500000;
  public:
    void pushBack(int num){
        a[sz] = num;
        sz++;
    }

    void pushFront(int num){
        start--;
        a[start] = num;
    }

    int len (){
        return sz-start;
    }

    int first(){
        return a[start];
    }

    int last(){
        return a[sz];
    }

    void popFront(){
        start++;
    }

    void popBack(){
        sz--;
    }
};

int main(){
    My_Dequeue q;

    q.pushBack(1);
    q.pushBack(2);
    cout<<q.first()<<endl;
    cout<<q.last()<<endl;
    q.pushFront(-1);
    q.pushFront(-2);
    cout<<q.first()<<endl;
    cout<<q.last()<<endl;



    for(int i = 0; i < q.len(); i++){
        cout<<i<<endl;
    }



    return 0;
}
