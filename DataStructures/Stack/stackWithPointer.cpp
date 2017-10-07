#include <iostream>

using namespace std;


int sz=0;

struct Node {
    int value;
    Node *L, *R;

    Node () {
        value = 0;
        L = R = NULL;
    }
};

Node* tmp = new Node();
Node* cur = new Node();

void push(int v){
    sz++;
    cur->value=v;
    tmp=cur;
    Node* newNode = new Node();
    cur->R=newNode;
    cur=cur->R;
    cur->L=tmp;
}

void pop(){
    if(sz>0){
        sz--;
        cur=tmp;
        tmp=tmp->L;
    }
}

int saiz(){
    return sz;
}

int top(){
    return cur->L->value;
}

bool isEmpty(){
    if(sz>0){
        return false;
    }else{
        return true;
    }
}



int main(){
    push(1);
    push(2);
    push(3);
    pop();
    cout<<"Size: "<<saiz()<<endl;
    cout<<"Top: "<<top()<<endl;

    return 0;
}
