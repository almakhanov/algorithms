#include <iostream>

using namespace std;

class BST{
    struct node{
        int data;
        node *left, *right;
    };

    node *root;

    node *insert(int x, node *t){
        if(t==NULL){
            t = new node;
            t->data=x;
            t->left = t->right = NULL;
        }else if(x<t->data){
            t->left = insert(x, t->left);
        }else if(x>=t->data){//all equal elements go to right branch
            t->right = insert(x, t->right);
        }
        return t;
    }

    node *findMin(node *t){
        if(t==NULL){
            return NULL;
        }else if(t->left==NULL){
            return t;
        }else{
            return findMin(t->left);
        }
    }

    node *findMax(node *t){
        if(t==NULL){
            return NULL;
        }else if(t->right==NULL){
            return t;
        }else{
            findMax(t->right);
        }
    }

    node *makeEmpty(node *t){
        if(t==NULL){
            return NULL;
        }else{
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node *remove(int x, node *t){
        node *tmp;
        if(t==NULL){
            return NULL;
        }else if(x<t->data){
            t->left = remove(x, t->left);
        }else if(x>t->data){
            t->right = remove(x, t->right);
        }else if(t->left && t->right){
            tmp = findMin(t->right);
            t->data = tmp->data;
            t->right = remove(t->data, t->right);
        }else{
            tmp = t;
            if(t->left == NULL){
                t = t->right;
            }else if(t->right == NULL){
                t = t->left;
            }
            delete tmp;
        }

        return t;
    }

    void printInOrder(node *t){
        if(t==NULL){
            return;
        }
        printInOrder(t->left);
        cout<<t->data<<endl;
        printInOrder(t->right);
    }

    node *find(node *t, int x){
        if(t==NULL){
            return NULL;
        }else if(x<t->data){
            t->left = find(t->left, x);
        }else if(x>t->data){
            t->right = find(t->right, x);
        }
        return t;
    }

public:
    BST(){
        root = NULL;
    }

    void insert(int x){
        root = insert(x, root);
    }

    void remove(int x){
        root = remove(x, root);
    }

    void display(){
        printInOrder(root);
    }

    void search(int x){
        root = find(root, x);
        cout<<root->data;
    }

    void clear(){
        root = makeEmpty(root);
    }

};

int main() {
    BST t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.display();

    cout<<"-----------------"<<endl;
    t.remove(20);
    t.display();
    cout<<"-----------------"<<endl;
    t.remove(25);
    t.display();
    cout<<"-----------------"<<endl;
    t.remove(30);
    t.display();
    cout<<"-----------------"<<endl;
    t.search(20);
}

