#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

typedef struct node* Tree;

Tree makeTree(int data){
    struct node *aux = (struct node*) malloc(sizeof(struct node));

    aux->data = data;
    aux->left = NULL;
    aux->right = NULL;

    return aux;
}

int Empty(Tree tr){
    if(tr == NULL)
        return 1;
    return 0;
}

int insert(Tree A, Tree sa){
    if(A == NULL)
        return 0;

    sa->right = A->left;
    A->left = sa;

    return 1;
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

int height(Tree tr){
    if(tr == NULL)
        return -1;

    int tmp = 1 + height(tr->left);
    int tmp2 = height(tr->right);

    return tmp > tmp2 ? tmp : tmp2;
}

void showTree(Tree tr){
    if(tr == NULL){
        printf("Empty");
        return;
    }

    printf("<%d", tr->data);
    showTree(tr->left);
    printf(">");
    showTree(tr->right);
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

    Tree A, B, C, D, E, F, G, H;

    A = makeTree(1);
    B = makeTree(2);
    C = makeTree(3);
    D = makeTree(4);
    E = makeTree(5);
    F = makeTree(6);
    G = makeTree(7);
    H = makeTree(8);


    insert(A, D);
    insert(A, C);
    insert(A, B);
    insert(B, E);
    insert(D, G);
    insert(D, F);
    insert(G, H);

    preOrder(A);

    printf("\nFound? %d", findElem(A, 9));

    printf("\nMax height: %d\n", height(A));

    freeTree(&A);

    return 0;
}
