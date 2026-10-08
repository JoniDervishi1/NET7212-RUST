#include <stdio.h>
#include <stdlib.h>

struct Node {
	int value; 
	struct Node* next; 
};

// Note: this may look like a constant based on naming convention, but without
// `const`, it's actually declared as a global variable
int kNumElements = 20;

struct Node* make_list() {
	// Make a list with one element
	struct Node* front = malloc(sizeof(struct Node));
	front->value = 0;
	front->next = NULL;

	struct Node* end = front;
	// Tack on 19 elements to the end of the list
	for (int i = 1; i < kNumElements; i++) {
		// Allocate a node and add it to the end of the list
		end->next = malloc(sizeof(struct Node));
		// Now, this new node is the end of the list
		end = end->next;
		// Initialize the new node
		end->value = i;
		end->next = NULL;
	}

	return front;
}

void swap_tenth_node(struct Node* list) {
	// Go to the 10th node
	struct Node* curr = list;
	for (int i = 0; i < 10; i++) {
		curr = curr->next;
	}

	// Replace the next node
	struct Node* nextNext = curr->next->next;
    //free(curr->next); //this free here was needed before mallocing again
	curr->next = malloc(sizeof(struct Node));
	curr->next->next = nextNext;
	curr->next->value = 100;
}

/**
 * Program is going to create a linked list with 20 nodes. Then, it will
 * replace the 10th node with a different one, and finally print/free the list.
 */
int main() {
	struct Node* list = make_list();

	// Swap a node
	swap_tenth_node(list); 
    /* Print and free everything */
	struct Node* curr = list;
    
    //free for 19 is not called, since its curr->next is null
	while (curr->next != NULL) {
		printf("%d and next %d \n", curr->value, curr->next->value);
		struct Node* next = curr->next;  
        printf("called\n");
		free(curr);
		curr = next;
	}
    //printf("outside of loop\n");
    //printf("%d\n", curr->value);  
	//free(curr);
    //printf("freed\n");
}
/*
joni@LAPTOP-V1875EKR:~/NET7212-RUST/lab2/ex2$ clang-tidy linkedlist.c -- -std=c17
1 warning generated.
/home/joni/NET7212-RUST/lab2/ex2/linkedlist.c:38:10: warning: Access to field 'next' results in a dereference of a null pointer (loaded from variable 'curr') [clang-analyzer-core.NullDereference]
   38 |                 curr = curr->next;
      |                        ^
/home/joni/NET7212-RUST/lab2/ex2/linkedlist.c:54:22: note: Calling 'make_list'
   54 |         struct Node* list = make_list();
      |                             ^~~~~~~~~~~
/home/joni/NET7212-RUST/lab2/ex2/linkedlist.c:17:2: note: Null pointer value stored to field 'next'
   17 |         front->next = NULL;
      |         ^~~~~~~~~~~~~~~~~~
/home/joni/NET7212-RUST/lab2/ex2/linkedlist.c:21:18: note: Assuming 'i' is >= 'kNumElements'
   21 |         for (int i = 1; i < kNumElements; i++) {
      |                         ^~~~~~~~~~~~~~~~
/home/joni/NET7212-RUST/lab2/ex2/linkedlist.c:21:2: note: Loop condition is false. Execution continues on line 31
   21 |         for (int i = 1; i < kNumElements; i++) {
      |         ^
/home/joni/NET7212-RUST/lab2/ex2/linkedlist.c:54:22: note: Returning from 'make_list'
   54 |         struct Node* list = make_list();
      |                             ^~~~~~~~~~~
/home/joni/NET7212-RUST/lab2/ex2/linkedlist.c:57:2: note: Calling 'swap_tenth_node'
   57 |         swap_tenth_node(list); 
      |         ^~~~~~~~~~~~~~~~~~~~~
/home/joni/NET7212-RUST/lab2/ex2/linkedlist.c:37:2: note: Loop condition is true.  Entering loop body
   37 |         for (int i = 0; i < 10; i++) {
      |         ^
/home/joni/NET7212-RUST/lab2/ex2/linkedlist.c:38:3: note: Null pointer value stored to 'curr'
   38 |                 curr = curr->next;
      |                 ^~~~~~~~~~~~~~~~~
/home/joni/NET7212-RUST/lab2/ex2/linkedlist.c:37:2: note: Loop condition is true.  Entering loop body
   37 |         for (int i = 0; i < 10; i++) {
      |         ^
/home/joni/NET7212-RUST/lab2/ex2/linkedlist.c:38:10: note: Access to field 'next' results in a dereference of a null pointer (loaded from variable 'curr')
   38 |                 curr = curr->next;

*/