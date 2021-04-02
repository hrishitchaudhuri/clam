#include<stdio.h>
#include<stdlib.h>

#include"clist.h"

List *initList() {
    List *ls = (List *) malloc(sizeof(List));
    ls->arr = (int *) malloc(sizeof(int));
    ls->size = 1;
    ls->count = 0;

    return ls;
}

void appendList(List *ls, int n) {
    if (ls->count == ls->size) {
        int new_sz = 2 * ls->size;

        ls->arr = (int *) realloc(ls->arr, new_sz * sizeof(int));
        ls->size = new_sz;
    }

    ls->arr[ls->count] = n;
    ls->count++;
}

void insertList(List *ls, int pos, int n) {
    int curr, prev;

    if (pos < 0 | pos > ls->count - 1) {
        printf("[ERR] IndexError: List position out of bounds.\n");
        exit(-1);
    }

    if (ls->count == ls->size) {
        int new_sz = 2 * ls->size;

        ls->arr = (int *) realloc(ls->arr, new_sz * sizeof(int));
        ls->size = new_sz;
    }

    curr = ls->arr[pos];
    ls->arr[pos] = n;
    prev = curr;

    pos++;

    while (pos < ls->count) {
        curr = ls->arr[pos];
        ls->arr[pos] = prev;
        prev = curr;

        pos++;
    }

    ls->arr[pos] = prev;
    ls->count++;
}

int popList(List *ls) {
    int ret_val, new_sz;

    if (ls->count == 0) {
        printf("[ERR] IndexError: List position out of bounds.\n");
        exit(0);
    }

    ls->count--;
    ret_val = ls->arr[ls->count];
    
    if (ls->count == ls->size / 2) {
        new_sz = ls->size / 2;

        ls->arr = (int *) realloc(ls->arr, new_sz * sizeof(int));
        ls->size = new_sz;
    }

    return ret_val;
}

int removeList(List *ls, int pos) {
    int next, ret_val, new_sz;

    if (pos < 0 | pos > ls->count - 1) {
        printf("[ERR] IndexError: List position out of bounds.\n");
        exit(-1);
    }

    ret_val = ls->arr[pos];
    next = ls->arr[pos + 1];
    ls->arr[pos] = next;
    
    pos++;

    while (pos < ls->count - 1) {
        next = ls->arr[pos + 1];
        ls->arr[pos] = next;

        pos++;
    }

    ls->count--;
    if (ls->count == ls->size / 2) {
        new_sz = ls->size / 2;

        ls->arr = (int *) realloc(ls->arr, new_sz * sizeof(int));
        ls->size = new_sz;
    }

    return ret_val;
}

List *concatLists(List *ls1, List *ls2) {
    List *ls = initList();

    for (register int i = 0; i < ls1->count; i++)
        appendList(ls, ls1->arr[i]);

    for (register int i = 0; i < ls2->count; i++)
        appendList(ls, ls2->arr[i]);

    return ls;
}

void printList(List *ls) {
    // printf("SIZE: %d\nCOUNT: %d\n", ls->size, ls->count);
    printf("[ ");
    for (register int i = 0; i < ls->count; i++)
        printf("%d ", ls->arr[i]);
    printf("]\n");
}