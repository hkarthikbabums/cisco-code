#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

// the definition of our circular buffer structure
typedef struct {
    void* buffer;
    size_t data_size;
    int head;
    int tail;
} circularBuffer;

// creates a new circular buffer and returns a pointer to it
circularBuffer* createBuffer(size_t data_size) {
    circularBuffer* cb = (circularBuffer*)malloc(sizeof(circularBuffer));
    cb->buffer = malloc(MAX_SIZE * data_size);
    cb->data_size = data_size;
    cb->head = 0;
    cb->tail = 0;
    return cb;
}

// checks if the buffer is full and returns a boolean value 
// 1 for full, 0 for not full
int isFull(circularBuffer* cb) {
    return (cb->head == (cb->tail + 1) % MAX_SIZE);
}

// checks if the buffer is empty and returns a boolean value
// 1 for empty, 0 for not empty
int isEmpty(circularBuffer* cb) {
    return (cb->head == cb->tail);
}

// adds a new piece of data to the buffer
void addData(circularBuffer* cb, void* data) {
    if (!isFull(cb)) {
        memcpy(cb->buffer + (cb->tail * cb->data_size), data, cb->data_size);
        cb->tail = (cb->tail + 1) % MAX_SIZE;
    }
    else {
        printf("Error: Buffer is full\n");
    }
}

// removes the oldest piece of data from the buffer
void deleteData(circularBuffer* cb) {
    if (!isEmpty(cb)) {
        cb->head = (cb->head + 1) % MAX_SIZE;
    }
    else {
        printf("Error: Buffer is empty\n");
    }
}

// returns a pointer to the oldest piece of data in the buffer
void* peekData(circularBuffer* cb) {
    if (!isEmpty(cb)) {
        return cb->buffer + (cb->head * cb->data_size);
    }
    else {
        printf("Error: Buffer is empty\n");
        return NULL;
    }
}

// main function
int main() {
    int choice = 0;
    printf("Enter the data type for buffer\n");
    printf("1. Char\n2. Int\n3. Float\n4. Double\n5. void*\n");
    scanf("%d", &choice);
    size_t data_size;
    switch (choice) {
        case 1:
            data_size = sizeof(char);
            break;
        case 2:
            data_size = sizeof(int);
            break;
        case 3:
            data_size = sizeof(float);
            break;
        case 4:
            data_size = sizeof(double);
            break;
        case 5:
            data_size = sizeof(void*);
            break;
        default:
            printf("Invalid choice\n");
            return 0;
    }

    circularBuffer* cb = createBuffer(data_size);
    
    // test the buffer operations
    
    char test_char = 'A';
    addData(cb, &test_char);
    printf("Peek data: %c\n", *(char*)peekData(cb));
    printf("After Adding - Buffer is empty: %d\n", isEmpty(cb));
    deleteData(cb);
    printf("After Deleting - Buffer is empty: %d\n", isEmpty(cb));

    //int test_int = 123;
    //addData(cb, &test_int);
    //printf("Peek data: %d\n", *(int*)peekData(cb));
    //printf("After Adding - Buffer is empty: %d\n", isEmpty(cb));
    //deleteData(cb);
    //printf("After Deleting - Buffer is empty: %d\n", isEmpty(cb));

    //float test_float = 1.23;
    //addData(cb, &test_float);
    //printf("Peek data: %f\n", *(float*)peekData(cb));
    //printf("After Adding - Buffer is empty: %d\n", isEmpty(cb));
    //deleteData(cb);
    //printf("After Deleting - Buffer is empty: %d\n", isEmpty(cb));

    //double test_double = 1.234;
    //addData(cb, &test_double);
    //printf("Peek data: %lf\n", *(double*)peekData(cb));
    //printf("After Adding - Buffer is empty: %d\n", isEmpty(cb));
    //deleteData(cb);
    //printf("After Deleting - Buffer is empty: %d\n", isEmpty(cb));

    //void* test_void = malloc(sizeof(int));
    //*(int*)test_void = 345;
    //addData(cb, test_void);
    //printf("Peek data: %d\n", *(int*)peekData(cb));
    //free(test_void);

    return 0;
}

