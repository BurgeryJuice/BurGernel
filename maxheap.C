#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct heap{
int data[100];
int l;
}heap;
int parent(int p){
    return (p-1)/2;
}
void insert(heap* a,int val){
    if (a->l>=100){
        printf("\n HEAP FULL");
        return;
    }
    a->data[a->l] = val;
    int pos = a->l;
    a->l++;
    while(pos>0 && a->data[parent(pos)]<val){
        int temp = a->data[pos];
        a->data[pos] = a->data[parent(pos)];
        a->data[parent(pos)] = temp;
        pos = parent(pos);
    }
    

}
void display(heap* a){
    for(int i = 0;i<a->l;i++){
        printf("%d ",a->data[i]);
    }
    printf("\n");
    return;
}

int main(){
    heap a;
    a.l = 0;
    insert(&a,30);
    insert(&a,10);
    insert(&a,50);
    insert(&a,2);
    insert(&a,15);
    display(&a);
    return 0;
}