# Heap Insert / Binary Tree Node

This directory implements part of a Max Binary Heap / Binary Tree project.

## Task 0: New Node
Function that creates a binary tree node.

Prototype:
```
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
```

Behavior:
- Allocates a new node.
- Sets its integer value and parent pointer.
- Initializes left and right child pointers to `NULL`.
- Returns `NULL` on allocation failure.

## Data Structures
```c
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;
```

## Compilation
Example (assuming you also have `binary_tree_print.c` and a test `0-main.c`):

```bash
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
./0-node
```

## Betty Style
All code follows Betty style guidelines.

## Files
- `binary_trees.h` - Header with struct definitions & prototype.
- `0-binary_tree_node.c` - Implementation of `binary_tree_node`.

## Author
Implementation added via AI assistant session.
