#include <iostream>

using namespace std;

class Heap{
    struct HeapElement{
        double data;
        HeapElement *left, *right;
    };

    HeapElement *root;

    HeapElement *insert(int x, HeapElement *t){
        if(t==NULL){
            t = new HeapElement;
            t->data=x;
            t->left = t->right = NULL;
        }else if(t->left == NULL){
            t->left = insert(x, t->left);
        }else if(t->right == NULL){
            t->right = insert(x, t->right);
        }
        return t;
    }

    HeapElement *findLast(HeapElement *t){
        if(t==NULL){
            return NULL;
        }else if(t->left==NULL){
            return t;
        }else if(t->right==NULL){
            return t->left;
        }else{
            //findLast()
        }
    }



};

int main() {

}

