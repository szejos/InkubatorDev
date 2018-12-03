#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


// struct for nodes in list
struct allocStruct
{
  size_t size;
  struct allocStruct *nextNode;
  void *pointer;
};


struct allocStruct *currentNode = NULL;

unsigned long long get_currently_allocated_size(void)
{
    unsigned long long allocatedSize = 0;
    struct allocStruct *tempPointer = currentNode;

    // while there are nodes in list, add size of the current node
    while(tempPointer != NULL)
    {
        allocatedSize += tempPointer->size;
        tempPointer = tempPointer->nextNode;
    }

    return allocatedSize;
}

void *mem_alloc(size_t size)
{
    // classic alloc with size as arg
    void *pointer = malloc(size);

    struct allocStruct *tempPointer = currentNode;
    struct allocStruct *newNode = malloc( sizeof(struct allocStruct) );


    newNode->pointer = pointer;
    newNode->size = size;

    // newNode is now the current node
    currentNode = newNode;

    // new node is pointing back at the prev node
    currentNode->nextNode = tempPointer;

    // return only the pointer to the allcated memory
    return pointer;
}

void mem_free(void* _pointer)
{
    struct allocStruct *crrNode;
    struct allocStruct *preNode;

    // if there are no nodes
    if(currentNode == NULL)
    {
        return;
    }
    // if the current node is the matching one
    if(currentNode->pointer == _pointer)
    {
        crrNode = currentNode;
        currentNode = currentNode->nextNode;
        free(crrNode);
    }
    else
    {
        preNode = currentNode;
        crrNode = currentNode->nextNode;
        while(crrNode->pointer != _pointer)
        {
            preNode = crrNode;
            crrNode = crrNode->nextNode;
        }
        preNode->nextNode = crrNode->nextNode;
        free(crrNode);
     }

     free(_pointer);
}

void test_cases()
{
     const size_t allocs[] = { 10, 5, 23, 16 };
     const size_t allocsSize = sizeof(allocs)/sizeof(allocs[0]);

     void *ptrs[allocsSize];

     unsigned long long allocated = 0;
     unsigned long long received = 0;

     for (size_t index = 0; index < allocsSize; ++index)
     {
         ptrs[index] = mem_alloc(allocs[index]);
         allocated += allocs[index];
     }

     for (size_t index = 0; index < allocsSize; ++index)
     {
       received = get_currently_allocated_size();
       assert( (received == allocated ) == true);
       mem_free(ptrs[index]);
       allocated -= allocs[index];
     }
}


int main()
{

    test_cases();
    return 0;

}

