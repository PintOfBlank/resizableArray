#include <stdio.h>
#include <stdlib.h>
#define MAX_VALUE_INT 2147483647

typedef struct ArrayList {
    size_t size;
    size_t capacity;
    int *items;

} ArrayList;

ArrayList* new() {

    ArrayList *takenArrayList = malloc(sizeof(ArrayList));

    if (takenArrayList == NULL) {printf("Heap Allocation Failure For Struct\n");return NULL;}

    takenArrayList->capacity = 1;
    takenArrayList->size = 0;
    
    takenArrayList->items = malloc(sizeof(int) * takenArrayList->capacity);

    if (takenArrayList->items == NULL) {
        printf("Heap Allocation Failure For Array\n");
        free(takenArrayList);
        return NULL;
    }

    return takenArrayList;

}

void *append(int valuePushed, struct ArrayList* takenArray) {

    if (valuePushed > (int)MAX_VALUE_INT) {
        printf("Value Pushed Onto Array Reaches Integer Value Store Limit"); 
        return NULL;
    }

    if (takenArray->size >= takenArray->capacity) {


        takenArray->items = realloc(takenArray->items, sizeof(int) * (takenArray->capacity + 10));

        if (takenArray->items == NULL) {
            printf("Reallocation Heap Failure");
            return NULL;
        }

        takenArray->capacity += 10;
        
    }

    takenArray->items[takenArray->size] = valuePushed;    
    takenArray->size++;
    return 0;

}

void *pop(unsigned int index, ArrayList* takenArray) {

    if (index > takenArray->size) {
        printf("Pop Value Out Of ArrayList");
        return NULL;

    }

    for (int pushBack = index; pushBack < takenArray->size; pushBack++) {
        if (pushBack+1 > takenArray->size) { 
            break;
        }

        takenArray->items[pushBack] = takenArray->items[pushBack+1];
    }

    takenArray->items = realloc(takenArray->items, (sizeof(int) * takenArray->capacity) - sizeof(int));
    takenArray->size--;
    takenArray->capacity--;
    return 0;
}

void destory(struct ArrayList* takenArray) {
    free(takenArray->items);
}

int main(){}

