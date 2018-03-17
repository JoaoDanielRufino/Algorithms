#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

typedef struct node* Tree;

Tree makeTree(){
    return NULL;
}

int Empty(Tree tr){
    if(tr == NULL)
        return 1;
    return 0;
}

Tree insert(Tree left, Tree right, int data){
    struct node *aux = (struct node*) malloc(sizeof(struct node));

    aux->data = data;
    aux->left = left;
    aux->right = right;

    return aux;
}

int findElem(Tree tr, int elem){
    if(tr == NULL)
        return 0;

    if(tr->data == elem)
        return 1;

    if(findElem(tr->left, elem))
        return 1;

    return findElem(tr->right, elem);
}

int removeLeaf(Tree* tr, int elem){
    if(*tr == NULL)
        return 0;

    if((*tr)->data == elem){
        if((*tr)->left == NULL && (*tr)->right == NULL){
            free(*tr);
            *tr = NULL;
            return 1;
        }
        return 0;
    }
    else{
        removeLeaf(&((*tr)->left), elem);
        if((*tr)->left == NULL)
            return 1;
        removeLeaf(&((*tr)->right), elem);
        if((*tr)->right == NULL)
            return 1;
        return 0;
    }
}

int height(Tree tr){
    if(tr == NULL)
        return -1;

    int tmp = 1 + height(tr->left);
    int tmp1 = 1 + height(tr->right);

    if(tmp < tmp1)
        return tmp1;
    return tmp;
}

Tree findParent(Tree tr, int elem){
    if(tr == NULL)
        return NULL;

    if(tr->left != NULL){
        if(tr->left->data == elem)
            return tr;
    }

    if(tr->right != NULL){
        if(tr->right->data == elem)
            return tr;
    }

    Tree aux = findParent(tr->left, elem);
    if(aux != NULL)
        return aux;

    return findParent(tr->right, elem);
}

void showTree(Tree tr){
    if(tr == NULL){
        printf("<>");
        return;
    }

    printf("<%d", tr->data);
    showTree(tr->left);
    showTree(tr->right);
    printf(">");
}

void preOrder(Tree tr){
    if(tr == NULL)
        return;

    printf("%d ", tr->data);
    preOrder(tr->left);
    preOrder(tr->right);
}

void inOrder(Tree tr){
    if(tr == NULL)
        return;

    inOrder(tr->left);
    printf("%d ", tr->data);
    inOrder(tr->right);
}

void postOrder(Tree tr){
    if(tr == NULL)
        return;

    postOrder(tr->left);
    postOrder(tr->right);
    printf("%d ", tr->data);
}

void freeTree(Tree* tr){
    if(*tr != NULL){
        freeTree(&((*tr)->left));
        freeTree(&((*tr)->right));
        free(*tr);
    }
    tr = NULL;
}

int main(){

    Tree A, B, C, D, E, F;

    F = insert(NULL, NULL, 1);
    E = insert(NULL, NULL, 8);
    D = insert(NULL, NULL, 4);
    C = insert(D, E, 7);
    B = insert(F, NULL, 2);
    A = insert(B, C, 5);

    showTree(A);
    printf("\n");
    //removeLeaf(&A, 7);

    //printf("%d", removeLeaf(&A, 7));

    //showTree(A);

    preOrder(A);
    printf("\n");
    //printf("%d", height(A));

    Tree aux = findParent(A, 1);

    if(aux == NULL)
        printf("NULL");

    if(aux != NULL)
        printf("%d", aux->data);

    //preOrder(A);

    printf("\n");

    freeTree(&A);

    return 0;
}
