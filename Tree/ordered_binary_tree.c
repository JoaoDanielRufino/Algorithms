#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reg{
    int data,age,salary;
    char name[100];
}Reg;

typedef struct node{
    Reg info;
    struct node *left,*right;
}Tree;

Reg make_reg(int data, int age, char *name){
    Reg new;

    new.data = data;
    new.age = age;
    strcpy(new.name, name);

    return new;
}

Tree* makeTree(){
    return NULL;
}

int Empty(Tree *tr){
    if(tr == NULL)
        return 1;
    return 0;
}

int insert(Tree **tr, Reg elem){
    if(tr == NULL)
        return 0;

    if(*tr == NULL){
        Tree *aux = (Tree*) malloc(sizeof(Tree));

        aux->info = elem;
        aux->left = NULL;
        aux->right = NULL;
        *tr = aux;

        return 1;
    }

    if(elem.data > (*tr)->info.data)
        insert(&((*tr)->right), elem);
    else
        insert(&((*tr)->left), elem);
}

int ord_remove(Tree **tr, int data){
    if(tr == NULL || *tr == NULL)
        return 0;

    if(data > (*tr)->info.data)
        return ord_remove(&((*tr)->right), data);
    if(data < (*tr)->info.data)
        return ord_remove(&((*tr)->left), data);

    if((*tr)->left == NULL && (*tr)->right == NULL){
        free(*tr);
        *tr = NULL;
        return 1;
    }

    if((*tr)->left != NULL && (*tr)->right == NULL){
        Tree *aux = *tr;
        *tr = (*tr)->left;
        free(aux);
        return 1;
    }

    if((*tr)->left == NULL && (*tr)->right != NULL){
        Tree *aux = *tr;
        *tr = (*tr)->right;
        free(aux);
        return 1;
    }

    Tree *aux = (*tr)->left;
    while(aux->right != NULL)
        aux = aux->right;

    (*tr)->info = aux->info;
    return ord_remove(&(*tr)->left, aux->info.data);
}

int findElem(Tree *tr, int data){
    if(tr == NULL)
        return 0;

    if(tr->info.data == data)
        return 1;

    if(data > tr->info.data)
        findElem(tr->right, data);
    else
        findElem(tr->left, data);
}

void showTree(Tree *tr){
    if(tr == NULL){
        printf("<>");
        return;
    }

    printf("<%d", tr->info.data);
    showTree(tr->left);
    showTree(tr->right);
    printf(">");
}

void preOrder(Tree *tr){
    if(tr == NULL)
        return;

    printf("%d ", tr->info.data);
    preOrder(tr->left);
    preOrder(tr->right);
}

void inOrder(Tree *tr){
    if(tr == NULL)
        return;

    inOrder(tr->left);
    printf("%d ", tr->info.data);
    inOrder(tr->right);
}

void postOrder(Tree *tr){
    if(tr == NULL)
        return;

    postOrder(tr->left);
    postOrder(tr->right);
    printf("%d ", tr->info.data);
}

void freeTree(Tree **tr){
    if(*tr != NULL){
        freeTree(&((*tr)->left));
        freeTree(&((*tr)->right));
        free(*tr);
    }
    *tr = NULL;
}

int main(){

    Tree *tr;
    Reg A, B, C, D;

    tr = makeTree();

    A = make_reg(5, 12, "Joao");
    B = make_reg(2, 16, "Pedro");
    C = make_reg(7, 14, "Matheus");
    D = make_reg(6, 12, "Lucas");

    insert(&tr, A);
    insert(&tr, B);
    insert(&tr, C);
    insert(&tr, D);

    inOrder(tr);

    //printf("Found? %d\n", findElem(tr, 4));

    ord_remove(&tr, 5);

    printf("\n");

    inOrder(tr);

    freeTree(&tr);

    return 0;
}
