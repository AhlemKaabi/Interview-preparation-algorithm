# **Heap Extract**

## **Problem statement**

Write a function that extracts the root node of a Max Binary Heap:

* Prototype: `int heap_extract(heap_t **root);`
* `root` is a double pointer to the root node of the heap
* Your function must return the value stored in the root node
* The root node must be freed and replace with the last `level-order` node of the heap
* Once replaced, the heap must be rebuilt if necessary
* If your function fails, return `0`.

Note: In order for the main file to compile, you are provided with the static library (file: `libheap.a`). This library won’t be used during correction, its only purpose is for testing.


## **Files:**

* binary_tree_print.c:

Contains functions to print binary trees in a pretty way:


```
                           .----------------------(006)-------.
                      .--(001)-------.                   .--(008)--.
                 .--(-02)       .--(003)-------.       (007)     (009)
       .-------(-06)          (002)       .--(005)
  .--(-08)--.                           (004)
(-09)     (-07)

```

**Resources:**

[Max Heap Insertion and Deletion | Heap Tree Insertion and Deletion with example| Data Structure](https://www.youtube.com/watch?v=NEtwJASLU8Q)[21:35]

[Heaps 3 - Extract Max](https://www.youtube.com/watch?v=mCG5V7yBOZA)