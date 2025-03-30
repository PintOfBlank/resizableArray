#include <stdio.h>
#include <stdlib.h>
#define MAX_VALUE_INT 2147483647

typedef struct ArrayList {
    size_t length;
    size_t capacity;
    int *array;

} ArrayList;

ArrayList* new() {

    ArrayList *takenArrayList = malloc(sizeof(ArrayList));

    if (takenArrayList == NULL) {printf("Heap Allocation Failure For Struct\n");return NULL;}

    takenArrayList->capacity = 1;
    takenArrayList->length = 0;
    
    takenArrayList->array = malloc(sizeof(int) * takenArrayList->capacity);

    if (takenArrayList->array == NULL) {
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

    if (takenArray->length >= takenArray->capacity) {

        takenArray->array = realloc(takenArray->array, sizeof(int) * (10 + takenArray->capacity));

        if (takenArray->array == NULL) {
            printf("Reallocation Heap Failure");
            return NULL;
        }

        takenArray->capacity += 10;
        
    }

    takenArray->array[takenArray->length] = valuePushed;    
    takenArray->length++;
    return 0;

}

void *pop(unsigned int index, ArrayList* takenArray) {

    if (index > takenArray->length) {
        printf("Pop Value Out Of ArrayList");
        return NULL;

    }

    for (int pushBack = index; pushBack < takenArray->length; pushBack++) {
        if (pushBack+1 > takenArray->length) { 
            break;
        }

        takenArray->array[pushBack] = takenArray->array[pushBack+1];
    }

    takenArray->array = realloc(takenArray->array, (sizeof(int) * takenArray->capacity) - sizeof(int));
    takenArray->length--;
    takenArray->capacity--;
    return 0;
}

void replace(unsigned int index, int value, ArrayList *takenArray) {
    takenArray->array[index] = value;
}

void* insert(unsigned int index, int value, ArrayList *takenArray) { 
    
    if (index > takenArray->length) {
        puts("Index Out Of Range!");
        return NULL;
    }
    
    if (index == takenArray->length) {append(value, takenArray);return 0;}

	if (takenArray->length == takenArray->capacity) {
	
		int *newArray = realloc(takenArray->array, sizeof(int) * (takenArray->capacity + 1));
		
		if (newArray == NULL) {
			puts("Heap Allocation Error.");
			return NULL;
		}

		takenArray->capacity++;
		takenArray->array = newArray;
	}

	takenArray->length++;
	
	for (int eachIteration = takenArray->length; eachIteration >= index; eachIteration--) {

		if (index == 0 && eachIteration == 0) {
			break;
		}
		
		takenArray->array[eachIteration] = takenArray->array[eachIteration-1];


		
	}

	takenArray->array[index] = value;

	return 0;
}

void destory(struct ArrayList* takenArray) {
    free(takenArray->array);
}

int main() {}
