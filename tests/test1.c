#include "../src/clist.h"

int main() {
    int n;
    List *ls = initList();

    printList(ls);
    appendList(ls, 1);
    printList(ls);
    
    appendList(ls, 4);
    appendList(ls, 9);
    appendList(ls, 7);
    printList(ls);

    appendList(ls, 10);
    printList(ls);

    n = popList(ls);
    printList(ls);
    printf("%d\n", n);

    appendList(ls, 24);
    appendList(ls, 96);
    appendList(ls, 23);
    appendList(ls, 45);

    printList(ls);

    insertList(ls, 2, 78);
    printList(ls);

    n = popList(ls);
    printList(ls);
    printf("%d\n", n);

    n = popList(ls);
    printList(ls);
    printf("%d\n", n);
    
    n = popList(ls);
    printList(ls);
    printf("%d\n", n);

    n = removeList(ls, 3);
    printList(ls);
    printf("%d\n", n);

    n = removeList(ls, 2);
    printList(ls);
    printf("%d\n", n);

    return 0;
}