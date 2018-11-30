#include <criterion/criterion.h>
#include <stdlib.h>

size_t get_currently_allocated_size(void);

void *mem_alloc(size_t size);

void mem_free(void*);

Test(ExampleTests, ShouldPassAllTheTestsProvided) {
  const size_t allocs[] = { 0, 5, 3, 16 };
  const size_t allocsSize = sizeof(allocs)/sizeof(allocs[0]);
  
  void *ptrs[allocsSize];
  
  unsigned long long allocated = 0;
  unsigned long long received = 0;
  
  for (size_t index = 0; index < allocsSize; ++index) 
  {
	  ptrs[index] = mem_alloc(allocs[index]);
    cr_assert(ptrs[index], 
      "mem_alloc returned a NULL. Allocation failed. \
      Please consult your implementation and try again.");
    
    allocated += allocs[index];
    received += allocs[index];
    
    cr_assert_eq(allocated, received, "Expected: %llu bytes. Received: %llu bytes.", allocated, received);
  }

  for (size_t index = 0; index < allocsSize; ++index) 
  {
    received = get_currently_allocated_size();
    cr_assert_eq(allocated, received, "Expected: %zd bytes. Received: %zd bytes.", allocated, received);
    
  	mem_free(ptrs[index]);
    allocated -= allocs[index];
    
    received = get_currently_allocated_size();
    cr_assert_eq(allocated, received, "Expected: %zd bytes. Received: %zd bytes.", allocated, received);
  }
}
