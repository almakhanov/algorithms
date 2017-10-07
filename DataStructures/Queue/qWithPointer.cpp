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
Node* start = new Node();

void push(int v){
    if(cur->L==NULL && cur->R==NULL){
        sz++;
        cur->value=v;
        tmp=cur;

        start=tmp;

        Node* newNode = new Node();
        cur->R=newNode;
        cur=cur->R;
        cur->L=tmp;
    }else{
        sz++;
        cur->value=v;
        tmp=cur;
        Node* newNode = new Node();
        cur->R=newNode;
        cur=cur->R;
        cur->L=tmp;
    }
}

void pop(){
    if(sz>0){
        sz--;
        start=start->R;
    }
}

int saiz(){
    return sz;
}

int first(){
    return start->value;
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
    cout<<"First: "<<first()<<endl;
    pop();
    cout<<"Size: "<<saiz()<<endl;
    cout<<"First: "<<first()<<endl;

    return 0;
}
