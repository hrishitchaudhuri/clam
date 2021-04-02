typedef struct List {
    int *arr;
    int count;
    int size;
} List;

List *initList();

void appendList(List *ls, int n);
void insertList(List *ls, int pos, int n);

int popList(List *ls);
int removeList(List *ls, int pos);

void printList(List *ls);
