# Cisco Coding Excercise
## _Problem Description with Outputs_


```sh

The design is to come up with a code for a circular buffer with user defined 
buffer data type. The user is prompted to select a data type for the buffer by entering a number 1-5. 

Enter the data type for buffer
1. Char
2. Int
3. Float
4. Double
5. void*

The program then uses the API functions,

addData
  // adds a new piece of data to the buffer
  void addData(circularBuffer* cb, void* data)
deleteData
  // removes the oldest piece of data from the buffer
  void deleteData(circularBuffer* cb)
peekData
  // returns a pointer to the oldest piece of data in the buffer
  void* peekData(circularBuffer* cb)
isFull
  // checks if the buffer is full and returns a boolean value
  // 1 for full, 0 for not full
  int isFull(circularBuffer* cb)
isEmpty
  // checks if the buffer is empty and returns a boolean value
  // 1 for empty, 0 for not empty
  int isEmpty(circularBuffer* cb)

     to add, delete, and peek data from the buffer, and check the buffer's fullness and emptiness. 
     The program will print out the peek data, to see the data stored in the buffer and check the buffer's fullness and emptiness.

Test Scenarios:

CHAR DATA TYPE:

    char test_char = 'A';
    addData(cb, &test_char);
    printf("Peek data: %c\n", *(char*)peekData(cb));
    printf("After Adding - Buffer is empty: %d\n", isEmpty(cb));
    deleteData(cb);
    printf("After Deleting - Buffer is empty: %d\n", isEmpty(cb));
    
    Output:
    
    Enter the data type for buffer
    1. Char
    2. Int
    3. Float
    4. Double
    5. void*
    1
    Peek data: A
    After Adding - Buffer is empty: 0
    After Deleting - Buffer is empty: 1
    
    
INT DATA TYPE:

    int test_int = 123;
    addData(cb, &test_int);
    printf("Peek data: %d\n", *(int*)peekData(cb));
    printf("After Adding - Buffer is empty: %d\n", isEmpty(cb));
    deleteData(cb);
    printf("After Deleting - Buffer is empty: %d\n", isEmpty(cb));
    
    Output:
    
    Enter the data type for buffer
    1. Char
    2. Int
    3. Float
    4. Double
    5. void*
    2
    Peek data: 123
    After Adding - Buffer is empty: 0
    After Deleting - Buffer is empty: 1

FLOAT DATA TYPE:

    float test_float = 1.23;
    addData(cb, &test_float);
    printf("Peek data: %f\n", *(float*)peekData(cb));
    printf("After Adding - Buffer is empty: %d\n", isEmpty(cb));
    deleteData(cb);
    printf("After Deleting - Buffer is empty: %d\n", isEmpty(cb));
    
    Output:
    
    Enter the data type for buffer
    1. Char
    2. Int
    3. Float
    4. Double
    5. void*
    3
    Peek data: 1.230000
    After Adding - Buffer is empty: 0
    After Deleting - Buffer is empty: 1

DOUBLE DATA TYPE:

    double test_double = 1.234;
    addData(cb, &test_double);
    printf("Peek data: %lf\n", *(double*)peekData(cb));
    printf("After Adding - Buffer is empty: %d\n", isEmpty(cb));
    deleteData(cb);
    printf("After Deleting - Buffer is empty: %d\n", isEmpty(cb));
    
    Output:
    
    Enter the data type for buffer
    1. Char
    2. Int
    3. Float
    4. Double
    5. void*
    4
    Peek data: 1.234000
    After Adding - Buffer is empty: 0
    After Deleting - Buffer is empty: 1

VOID DATA TYPE:

    void* test_void = malloc(sizeof(int));
    *(int*)test_void = 345;
    addData(cb, test_void);
    printf("Peek data: %d\n", *(int*)peekData(cb));
    printf("After Adding - Buffer is empty: %d\n", isEmpty(cb));
    free(test_void);
    printf("After Deleting - Buffer is empty: %d\n", isEmpty(cb));
    
    Output:
    
    Enter the data type for buffer
    1. Char
    2. Int
    3. Float
    4. Double
    5. void*
    5
    Peek data: 345
    
Limitation: 

It's important to note that this could be improved by adding error handling and other features, such as a dynamic buffer size, a user defined buffer size, adding more operations on the buffer.


```
