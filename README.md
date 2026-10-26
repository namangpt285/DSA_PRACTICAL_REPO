# Data Structures Practical File (C++)
**Submitted by:** NAMAN KUMAR GUPTA  
**Roll No:** UEM253140  
**Section:** CSE SEC - 2 (SEM 03)  

This repository contains the C++ implementations of various fundamental Data Structures and Algorithms completed as part of the DSA Practical coursework.

## Table of Contents
1. [Single Linked List](#1-single-linked-list)
2. [Doubly Linked List](#2-doubly-linked-list)
3. [Stack With Array](#3-stack-with-array)
4. [Stack With Linked List](#4-stack-with-linked-list)
5. [Queue with Array](#5-queue-with-array)
6. [Circular Queue](#6-circular-queue)
7. [Queue using Linked List](#7-queue-using-linked-list)
8. [Merge Sort](#8-merge-sort)
9. [Quick Sort](#9-quick-sort)
10. [Radix Sort](#10-radix-sort)
11. [Heap Sort](#11-heap-sort)
12. [Bucket Sort](#12-bucket-sort)
13. [Kth Smallest Element](#13-kth-smallest-element)
14. [Bin Sort](#14-bin-sort)
15. [Tower of Hanoi](#15-tower-of-hanoi)
16. [Binary Tree](#16-binary-tree)
17. [Binary Search Tree](#17-binary-search-tree)
18. [AVL Trees](#18-avl-trees)
19. [Parenthesis Matching](#19-parenthesis-matching)

## Running the files
Each `.cpp` file contains a complete implementation including the data structure class/methods and a `main()` function with test cases verifying functionality.

To run any of the programs, compile them via `g++`:
```bash
g++ 01_Single_Linked_List.cpp -o app
./app
```

---

<a id='1-single-linked-list'></a>
## 1. Single Linked List

### Description & Function Details
Implements a Singly Linked List.
- Node: A class containing 'data' and a 'next' pointer.
- InsertAtHead(head, d): Creates a new node and inserts it at the beginning of the list.
- InsetAtTail(tail, d): Inserts a new node at the very end.
- InsertAtMiddle(head, tail, position, d): Uses a 'cnt' counter to traverse to the (position-1)th node. Updates pointers to insert the new node in the middle.
- deleteNode(head, value): Searches for a node with the given 'value', maintaining a 'prev' pointer, and removes it.
- DeleteNode(head, position): Uses 'cnt' to traverse to a specific index and deletes the node at that position.
- Print(head): Traverses the list and prints all elements.

### Test Cases
- **Test Case 1: Perform insertions and deletions.**
  - **Input Operations:** `Insert 12, 15 at head. Insert 20, 25 at tail. Insert 22 at pos 6. Delete pos 6. Delete value 12.`
  - **Expected Output:**
```text
After Head Insertions: 15 12 10
After Tail Insertions: 15 12 10 20 25
After Middle Insertion (pos 6): 15 12 10 20 25 22
After Deleting pos 6: 15 12 10 20 25
After Deleting value 12: 15 10 20 25
```
### Complexity Metrics
- **Insertions:** `O(1) to O(n)`
- **Deletions:** `O(n)`
- **Print:** `O(n)`

---

<a id='2-doubly-linked-list'></a>
## 2. Doubly Linked List

### Description & Function Details
Implements a Doubly Linked List.
- Node: Contains 'data', 'next', and 'prev' pointers for bidirectional traversal.
- InsertAtHead(head, d): Sets new node as head, linking its 'next' to old head, and old head's 'prev' to it.
- InsertAtTail(tail, d): Links the new node to the end using the tail pointer.
- InsertAtMiddle(head, tail, pos, d): Uses 'cnt' to find insertion point, updates four pointers (prev/next of adjacent nodes).
- DeleteNode(head, position): Traverses to the position with 'cnt', unlinks the node by bypassing its 'next' and 'prev' links, and deletes it.
- getLength(head): Iterates through list to count the total number of elements.
- print(head): Displays list from head to tail.

### Test Cases
- **Test Case 1: Doubly LL Operations**
  - **Input Operations:** `Insert at head (12, 13). Insert at tail (23). Insert at mid (4, 523). Delete (pos 3).`
  - **Expected Output:**
```text
Initial List: 10
After Head Inserts: 13 12 10
After Tail Insert: 13 12 10 23
After Middle Insert: 13 12 10 523 23
After Deleting pos 3: 13 12 523 23
Final Length: 4
```
### Complexity Metrics
- **Insertions:** `O(1) to O(n)`
- **Deletions:** `O(n)`
- **Length/Print:** `O(n)`

---

<a id='3-stack-with-array'></a>
## 3. Stack With Array

### Description & Function Details
Implements a Stack using a static Array.
- Stack Class: Maintains a fixed integer array 'arr[10]', a 'capacity' variable, and a 'top' index (initially -1).
- push(x): Increments 'top' and places 'x' in the array. Throws 'Stack Overflow' if top == capacity - 1.
- pop(): Decrements 'top' to remove the most recent element. Handles 'Stack Underflow'.
- peek(): Returns the element at 'arr[top]' without modifying the stack.
- isEmpty() / isFull(): Boolean checks against the 'top' index.
- size(): Returns 'top + 1' to show active elements.
- print(): Iterates backward from 'top' down to 0 to simulate Top-to-Bottom stack viewing.

### Test Cases
- **Test Case 1: Stack Array Operations**
  - **Input Operations:** `Push(100), Push(200), Push(300). Peek. Pop. Check Size and Top.`
  - **Expected Output:**
```text
Stack Elements: 300 200 100
Top element: 300
After one pop: 200 100
New top element: 200
Stack size: 2
Is stack empty? No
Is stack full? No
```
### Complexity Metrics
- **Push / Pop / Peek:** `O(1)`
- **Print:** `O(n)`

---

<a id='4-stack-with-linked-list'></a>
## 4. Stack With Linked List

### Description & Function Details
Implements a Stack dynamically using a Linked List.
- Node: Dynamic memory representation. 'data' stores value, 'next' points to node directly below in stack.
- push(d, top): Allocates a new node, points its 'next' to the current 'top', and updates 'top' to this new node (LIFO behavior).
- pop(top): Unlinks the 'top' node, updating 'top' to 'top->next', and deletes the old top node to free memory.
- peek(top): Returns the 'data' at the 'top' node pointer.
- isEmpty(top): Checks if the 'top' pointer is NULL.
- size(top): Traverses from 'top' to NULL using a 'count' variable to determine total elements.
- print(top): Iterates through the linked list to display all elements.

### Test Cases
- **Test Case 1: Stack Linked List Operations**
  - **Input Operations:** `Push 10, 20, 30. Peek. Pop once. Check size.`
  - **Expected Output:**
```text
Stack: 30 20 10
Top element: 30
Stack size: 3
After pop: 20 10
Top element: 20
Is stack empty? No
```
### Complexity Metrics
- **Push / Pop / Peek:** `O(1)`
- **Size / Print:** `O(n)`

---

<a id='5-queue-with-array'></a>
## 5. Queue with Array

### Description & Function Details
Implements a Queue using a static Array.
- Queue Class: Fixed array 'arr[5]' using standard FIFO rules. Variables 'front' and 'rear' initialized to -1.
- enqueue(data): Increments 'rear' and places data at arr[rear]. If queue is empty, sets both front/rear to 0. Checks for overflow.
- dequeue(): Returns arr[front] and increments 'front' to remove element. If front == rear (last element removed), resets both to -1.
- frontElement(): Peeks at arr[front] without removal.
- isEmpty() / isFull(): Bounds checking for front==-1 or rear==4.
- display(): Iterates from 'front' index up to 'rear' index printing contents.

### Test Cases
- **Test Case 1: Linear Queue Array**
  - **Input Operations:** `Enqueue 10, 20, 30. Dequeue one. Enqueue 40, 50.`
  - **Expected Output:**
```text
Queue contents: 10 20 30
Dequeued: 10
Front element: 20
Queue contents after additions: 20 30 40 50
```
### Complexity Metrics
- **Enqueue / Dequeue:** `O(1)`
- **Display:** `O(n)`

---

<a id='6-circular-queue'></a>
## 6. Circular Queue

### Description & Function Details
Implements a Circular Queue using a Circular Linked List tail pointer.
- Node: Destructor includes a print statement to verify memory is freed.
- insertNode(tail, element, d): Mimics Circular Linked List logic. If list is empty, makes node point to itself. Otherwise, traverses to find 'element', and inserts 'd' right after it, keeping circular links intact.
- deleteNode(tail, value): Uses 'prev' and 'curr' to find the node with 'value'. Handles edge cases for deleting the tail pointer or the only node in list.
- print(tail): Uses a do-while loop to traverse starting from tail until it loops back to tail.

### Test Cases
- **Test Case 1: Circular Queue Operations**
  - **Input Operations:** `Insert multiple elements continuously wrapping around. Delete 10.`
  - **Expected Output:**
```text
3 5
3 5 7
3 5 7 9
3 5 6 7 9
3 5 6 7 9 10
Deleting node with value 10:
This memory is free for node with data 10
3 5 6 7 9
```
### Complexity Metrics
- **Search & Insert / Delete:** `O(n)`
- **Print:** `O(n)`

---

<a id='7-queue-using-linked-list'></a>
## 7. Queue using Linked List

### Description & Function Details
Implements a Queue dynamically using a Linked List.
- Queue Class: Contains two Node pointers: 'front' (for dequeuing) and 'rear' (for enqueuing), enforcing FIFO structure.
- enqueue(data): Creates a new node. If queue is empty, sets both front/rear to this node. Otherwise, links it to 'rear->next' and updates 'rear'.
- dequeue(): Extracts 'front->data', updates 'front' to 'front->next', and deletes the old front. If it was the last node, resets 'rear' to NULL too.
- frontElement(): Fetches 'front->data'.
- isEmpty(): Checks if 'front' is NULL.
- display(): Traverses from 'front' node iteratively to print active elements.

### Test Cases
- **Test Case 1: Linked List Queue**
  - **Input Operations:** `Enqueue 10, 20, 30. Dequeue once. Enqueue 40, 50.`
  - **Expected Output:**
```text
Queue elements: 10 20 30
Removed element: 10
Queue after modifications: 20 30 40 50
Front element currently is: 20
```
### Complexity Metrics
- **Enqueue / Dequeue:** `O(1)`
- **Display:** `O(n)`

---

<a id='8-merge-sort'></a>
## 8. Merge Sort

### Description & Function Details
Implements Merge Sort recursively.
- mergesort(arr, size, s, end): The recursive divide function. Calculates 'mid' and recursively calls itself for the left and right halves until base case (s >= end) is reached.
- merge(arr, s, e): The conquer function. Dynamically allocates two temp arrays ('first' with size 'len1' and 'second' with size 'len2') corresponding to the split halves. Uses two pointers ('index1', 'index2') to compare elements and merge them back into the main array 'arr' in sorted order, finally freeing memory.

### Test Cases
- **Test Case 1: Merge Sort**
  - **Input Operations:** `Input Array: {38, 27, 43, 3, 9, 82, 10}`
  - **Expected Output:**
```text
Original array: 38 27 43 3 9 82 10
SORTED ARRAY: 3 9 10 27 38 43 82
```
### Complexity Metrics
- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(n) auxiliary arrays`

---

<a id='9-quick-sort'></a>
## 9. Quick Sort

### Description & Function Details
Implements Quick Sort algorithm.
- partition(arr, s, e): Chooses 'arr[s]' as the pivot. Uses a loop and 'count' variable to find exact number of smaller elements. Swaps pivot to its rightful place ('pivotIndex'). Uses two pointers 'i' and 'j' approaching from opposite sides to ensure all elements to the left are smaller and right are larger.
- quicksort(arr, s, e): Recursive function that uses the pivotIndex returned by partition to independently sort the left and right subarrays in-place.

### Test Cases
- **Test Case 1: Quick Sort**
  - **Input Operations:** `Input Array: {9, 3, 7, 5, 6, 2, 8, 4, 1}`
  - **Expected Output:**
```text
Original array: 9 3 7 5 6 2 8 4 1
Sorted array: 1 2 3 4 5 6 7 8 9
```
### Complexity Metrics
- **Time Complexity:** `O(n log n) Avg, O(n^2) Worst`
- **Space Complexity:** `O(log n) stack`

---

<a id='10-radix-sort'></a>
## 10. Radix Sort

### Description & Function Details
Implements Radix Sort algorithm.
- getMax(arr, n): Utility function to iterate the array and find the maximum element (to determine how many digits/loops are needed).
- countSort(arr, n, exp): A stable counting sort implementation based on the specific digit (exp). It extracts the digit via '(arr[i]/exp)%10', stores occurrence counts in an array of size 10, calculates prefix sums, and positions elements in 'output' array in reverse traversal to maintain stability.
- radixSort(arr, n): Multiplies 'exp' by 10 continuously and runs countSort for every decimal place.

### Test Cases
- **Test Case 1: Radix Sort**
  - **Input Operations:** `Input Array: {253, 192, 3, 2, 10, 75, 478, 88}`
  - **Expected Output:**
```text
Original array: 253 192 3 2 10 75 478 88
Sorted array: 2 3 10 75 88 192 253 478
```
### Complexity Metrics
- **Time Complexity:** `O(d * (n + 10))`
- **Space Complexity:** `O(n + 10)`

---

<a id='11-heap-sort'></a>
## 11. Heap Sort

### Description & Function Details
Implements Heap Sort using Max-Heap.
- heapify(arr, n, i): Takes an array and normalizes a sub-tree rooted at node 'i' into a max-heap. It calculates 'left' (2i+1) and 'right' (2i+2) child indices and recursively swaps elements downwards if a child is larger than its parent ('largest' variable).
- heapSort(arr, n): Uses two loops. First loop calls heapify from the middle up to the root to build the initial max-heap. The second loop swaps the max element (at arr[0]) to the end, reduces heap size, and calls heapify(0) to settle the remaining elements.

### Test Cases
- **Test Case 1: Heap Sort**
  - **Input Operations:** `Input Array: {12, 11, 13, 5, 6, 7}`
  - **Expected Output:**
```text
Original array: 12 11 13 5 6 7
Sorted array: 5 6 7 11 12 13
```
### Complexity Metrics
- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(log n) recursion stack`

---

<a id='12-bucket-sort'></a>
## 12. Bucket Sort

### Description & Function Details
Implements Bucket Sort for floating point numbers.
- bucketSort(arr, n): Sort algorithm specifically optimal for elements uniformly distributed over a range (like floats 0.0-1.0). Creates an array of vectors `vector<float> bucket[10]` as the buckets.
- Step 1: Traverses 'arr' and multiplies element by 'n' to find its bucket 'index', appending it to that vector.
- Step 2: Runs the STL `sort` function on every individual bucket.
- Step 3: Gathers all values from every bucket and overwrites 'arr' in sequential order utilizing an index counter 'k'.

### Test Cases
- **Test Case 1: Bucket Sort**
  - **Input Operations:** `Input Array: {0.32, 0.67, 0.24, 0.75, 0.12, 0.88, 0.44}`
  - **Expected Output:**
```text
Original array: 0.32 0.67 0.24 0.75 0.12 0.88 0.44
Sorted array: 0.12 0.24 0.32 0.44 0.67 0.75 0.88
```
### Complexity Metrics
- **Time Complexity:** `O(n + k) average, O(n^2) worst`
- **Space Complexity:** `O(n) auxiliary buckets`

---

<a id='13-kth-smallest-element'></a>
## 13. Kth Smallest Element

### Description & Function Details
Finds the Kth smallest element using Quickselect.
- partition(arr, s, e): Re-utilizes the exact Quick Sort partitioning logic. Counts elements smaller than pivot to find correct placement index. Divides elements such that left side is smaller.
- kthSmallest(arr, s, e, k): Implements Quickselect logic. Fetches a partition index 'p'. If 'p' matches 'k' (our target rank index), it returns `arr[p]`. Otherwise, it makes a single recursive call to either the left chunk (p > k) or right chunk (p < k) rather than sorting the whole array.

### Test Cases
- **Test Case 1: Quickselect element access**
  - **Input Operations:** `Input Array: {10, 4, 5, 8, 6, 11, 26}, k = 3 (0-indexed, meaning 4th smallest element)`
  - **Expected Output:**
```text
Array: 10 4 5 8 6 11 26
Element at sorted index 3 is: 8
```
### Complexity Metrics
- **Time Complexity:** `O(n) average, O(n^2) worst`
- **Space Complexity:** `O(log n) recursive stack`

---

<a id='14-bin-sort'></a>
## 14. Bin Sort

### Description & Function Details
Implements Bin Sort using Linked Lists.
- Node: Simple list node used to manage chaining in bins.
- binSort(arr, n, maxVal): Takes array and absolute max limit 'maxVal'. Allocates an array of Node pointers (`Node** bins`) of size maxVal+1 initialized to NULL.
- Distribute: Iterates over input elements. It uses element values directly as the index to target the specific bin. Inserts a new node at the head of that bin's linked list (chaining for duplicates).
- Gather: Iterates from 0 up to maxVal over the bins. For each active list, extracts data sequentially overriding the main 'arr', traversing node by node and explicitly deleting nodes to free memory.

### Test Cases
- **Test Case 1: Bin Sort execution**
  - **Input Operations:** `Input Array: {4, 2, 0, 4, 1, 3, 2, 5}, maxVal = 5`
  - **Expected Output:**
```text
Original array: 4 2 0 4 1 3 2 5
Sorted array: 0 1 2 2 3 4 4 5
```
### Complexity Metrics
- **Time Complexity:** `O(n + maxVal)`
- **Space Complexity:** `O(n + maxVal) structure overhead`

---

<a id='15-tower-of-hanoi'></a>
## 15. Tower of Hanoi

### Description & Function Details
Solves Tower of Hanoi using Recursion.
- towerOfHanoi(n, src, helper, dest): Defines base case logic for resolving recursive disk swaps.
- Base Case: When `n == 1`, prints the move from `src` directly to `dest` and returns.
- Recurrence: 1) Recursively calls itself to move `n-1` disks from `src` to `helper`. 2) Prints moving the largest `nth` disk directly to `dest`. 3) Recursively calls itself to move the `n-1` disks from `helper` onto `dest`.
- No data structures are needed; state is strictly maintained in the call stack.

### Test Cases
- **Test Case 1: Tower of Hanoi Logic**
  - **Input Operations:** `towerOfHanoi(3, 'A', 'B', 'C')`
  - **Expected Output:**
```text
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
```
### Complexity Metrics
- **Time Complexity:** `O(2^n)`
- **Space Complexity:** `O(n)`

---

<a id='16-binary-tree'></a>
## 16. Binary Tree

### Description & Function Details
Implements a standard Binary Tree structure.
- Node: Simple binary node with 'data', 'left', and 'right' pointers.
- insert(root, d): Interactive recursive terminal input function. Asks via 'cin' if the user wants to add a left/right child, taking input dynamically to flesh out the tree structure.
- Traversals (inorder, preorder, postorder): Recursively visits nodes depending on standard tree logic rules.
- Level_order(root): Implements a Breadth-First traversal utilizing the `<queue>` STL template.
- search(root, key): Boolean recursion to look up 'key'.
- count_nodes(root) / height_tree(root): Returns 1 + left + right traversal properties recursively.
- max_val(root): Traverses entirely to fetch mathematical peak using std::max.
- deleteNode(root, key): Replaces targeted node's data with the data from the deepest rightmost node found by standard level order traversal, then calls deleteDeepest() to cull that extra leaf from memory safely.

### Test Cases
- **Test Case 1: Comprehensive Tree Execution**
  - **Input Operations:** `Root=10, left=20, right=30. Search 20. Delete 20.`
  - **Expected Output:**
```text
Preorder traversal: 10 20 30
Inorder traversal: 20 10 30
Postorder traversal: 20 30 10
Total nodes: 3
Height: 2
Max value: 30
Level order traversal: 10 20 30
Searching for 20: Found
Deleting 20...
Level order after deletion: 10 30
```
### Complexity Metrics
- **Metrics / Traversals:** `O(n)`
- **Deletion / Search:** `O(n)`

---

<a id='17-binary-search-tree'></a>
## 17. Binary Search Tree

### Description & Function Details
Implements a Binary Search Tree (BST).
- insert(root, d): Recursive bounds-aware insertion keeping BST rules (smaller to left, larger to right). Prevents duplicates.
- buildBST(root): Reads integer stream until boolean stop flag trips.
- Traversals (inorder, preorder, postorder): Recursively visits nodes.
- searchBST(root, key): Performs O(h) navigation checking `key < data` constraints.
- findMin(root) / findMax(root): Traverses purely leftmost or rightmost iteratively to fetch the boundaries.
- isBST(root, low, high): A validation protocol applying MIN/MAX clamping constraints top-down.
- deletionBST(root, value): Modifies tree resolving 3 cases. Case 1: Simple leaf deletion by resetting parent pointer to NULL. Case 2: One child exists, unlinks current node and bypasses reference to the lonely child. Case 3: Both children exist, locates right minimum ('findMin'), overwrites the active node data with it, then safely performs deletion on that min leaf below.

### Test Cases
- **Test Case 1: BST Operations**
  - **Input Operations:** `Insert 10, 5, 15, 3, 7. Verify boundaries and search. Delete root 10.`
  - **Expected Output:**
```text
Initial Inorder traversal: 3 5 7 10 15
Min Val: 3 | Max Val: 15
Is Valid BST? Yes
Search for 15: Found
Deleting Node 10 (Root with two children)...
After Deletion Inorder: 3 5 7 15
```
### Complexity Metrics
- **Insertion/Deletion:** `O(h)`
- **Validation/Traversal:** `O(n)`

---

<a id='18-avl-trees'></a>
## 18. AVL Trees

### Description & Function Details
Implements a self-balancing AVL Tree.
- Node: Tracks an explicit 'height' integer metric on top of left/right pointers.
- getHeight(root) / getBalance(root): Computes the differential scale between left sub-tree heights and right sub-tree heights. If the abs value exceeds 1, a rotation is fired.
- rightRotate(y) / leftRotate(x): Resolves heavy imbalanced sub-trees securely swapping node references iteratively without losing data references. They correctly update respective heights simultaneously.
- insert(root, key): Triggers standard BST insertion. Post-insert, actively checks balance factor constraints up the recursive path and fixes Left-Left, Left-Right, Right-Right, Right-Left patterns natively.

### Test Cases
- **Test Case 1: AVL Height Balance Verification**
  - **Input Operations:** `Input Array: {12, 34, 26, 13, 54, 9, 21}`
  - **Expected Output:**
```text
Inserting sequence: 12, 34, 26, 13, 54, 9, 21
Inorder traversal ensures sorted property: 9 12 13 21 26 34 54
Tree root value is naturally balanced to: 26
Root Balance Factor: 0
```
### Complexity Metrics
- **All Search/Insert Ops:** `O(log n) strict bound`

---

<a id='19-parenthesis-matching'></a>
## 19. Parenthesis Matching

### Description & Function Details
Checks bracket parity using STL Stack.
- isBalanced(string expr): The main processor logic. Initializes a `<stack<char>> s`. Loops through characters in the string sequence via `expr[i]`.
- Opening Brackets: For every '(', '{', or '[', the item gets pushed onto the internal stack directly.
- Closing Brackets: When a ')', '}', or ']' is found, it confirms the stack isn't completely empty natively via `s.empty()`. It checks the `s.top()` character. If they align (e.g., '{' unspools with '}'), the top stack item pops. Otherwise, it hard fails returning false.
- Completion: At the final string index, it dictates success uniquely when the stack reports cleanly emptied out `s.empty()` indicating parity.

### Test Cases
- **Test Case 1: Stack String Evaluation**
  - **Input Operations:** `expr1 = "{[()]}" (valid), expr2 = "([)]" (invalid)`
  - **Expected Output:**
```text
Expression 1: {[()]} -> Balanced
Expression 2: ([)] -> Not Balanced
```
### Complexity Metrics
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

