#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *next;

    Node(){
        val=0;
        next=NULL;
    }
};

Node *head, *tail;

void sorting(){
    Node *tmp1 = new Node();
    tmp1 = head;

    while(tmp1!=NULL){
        Node *tmp2 = new Node();
        tmp2=tmp1->next;
        while(tmp2!=NULL){
            if(tmp1->val>tmp2->val){
                int tmp = tmp1->val;
                tmp1->val=tmp2->val;
                tmp2->val=tmp;
            }
            tmp2=tmp2->next;
        }
        tmp1=tmp1->next;

    }
}


void push(int v){
    Node *tmp = new Node();
    tmp->val=v;
    tmp->next=NULL;

    if(head==NULL){
        head = tmp;
        tail = tmp;
    }else{
        tail->next = tmp;
        tail = tmp;
    }

}


void show(){
    Node *tmp = new Node();
    tmp = head;
    while(tmp!=NULL){
        cout<<tmp->val<<' ';
        tmp = tmp->next;
    }
}


int main(){
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        push(x);
    }

    sorting();
    show();

    return 0;
}


