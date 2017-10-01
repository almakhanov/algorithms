
#include <iostream>

using namespace std;


int sz=0;

struct Node {
    long long value;
    Node *L, *R;

    Node () {
        value = 0;
        L = R = NULL;
    }
};

Node* tmp = new Node();
Node* cur = new Node();
Node* start = new Node();

void pushBack(long long v){
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

void pushFront(long long v){
    if(cur->L==NULL && cur->R==NULL){
        sz++;
        start->value=v;
        cur=start;
        tmp=cur;
        Node* newNode = new Node();
        cur->R=newNode;
        cur=cur->R;
        cur->L=tmp;
    }else{
        sz++;
        Node* newNode = new Node();
        newNode->value=v;
        newNode->R=start;
        start->L=newNode;
        tmp=start;
        start=newNode;
        start->R=tmp;
    }
}

void popFront(){
    if(sz==1){
        sz--;
        tmp = new Node();
        cur = new Node();
        start = new Node();
    }else if(sz>0){
        sz--;
        start=start->R;
    }
}
void popBack(){
    if(sz==1){
        sz--;
        tmp = new Node();
        cur = new Node();
        start = new Node();
    }
    else if(sz>0){
        sz--;
        cur=tmp;
        tmp=tmp->L;
    }
}

int saiz(){
    return sz;
}

int first(){
    if(sz==0){
        return 0;
    }
    int q=start->value;
    return q;
}
int last(){
    if(sz==0){
        return 0;
    }
    int q=cur->L->value;
    return q;
}

bool isEmpty(){
    if(sz>0){
        return false;
    }else{
        return true;
    }
}




int main(){
    pushBack(2);
    pushBack(3);
    pushBack(4);
    pushBack(5);
    popFront();
    popFront();
    popBack();
    pushFront(1);
    cout<<"First:"<<first()<<endl;
    cout<<"Last:"<<last()<<endl;
    cout<<"Empty:"<<isEmpty()<<endl;

    return 0;
}
