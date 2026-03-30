*This project has been created as part of the 42 curriculum by marmoldo.*

# Push_swap 

## Description
**Push_swap** is a highly efficient sorting algorithm project that challenges students to sort a random list of integers using two stacks (`a` and `b`) and a restricted set of operations. 

The goal is to sort the numbers in ascending order in stack `a` with the **minimum possible number of operations**. This project explores data structures, algorithm complexity ($O(n^2)$ vs $O(n \log n)$), and optimization techniques.

### Operations
| Command | Name            | Action                                                               |
| ------- | --------------- | -------------------------------------------------------------------- |
| sa      | swap a          | Swap the first 2 elements at the top of stack a.                     |
| sb      | swap b          | Swap the first 2 elements at the top of stack b.                     |
| ss      | swap both       | sa and sb at the same time.                                          |
| pa      | push a          | Take the first element at the top of b and put it at the top of a.   |
| pb      | push b          | Take the first element at the top of a and put it at the top of b.   |
| ra      | rotate a        | Shift up all elements of stack a by 1. The first becomes the last.   |
| rb      | rotate b        | Shift up all elements of stack b by 1. The first becomes the last.   |
| rr      | rotate both     | ra and rb at the same time.                                          |
| rra     | rev rotate a    | Shift down all elements of stack a by 1. The last becomes the first. |
| rrb     | rev rotate b    | Shift down all elements of stack b by 1. The last becomes the first. |
| rrr     | rev rotate both | rra and rrb at the same time.                                        |
---

### The Algorithm: "The Turk"
This implementation uses a variation of the **Turk Algorithm**. Instead of pre-sorting or using complex chunks, the algorithm:

#### Phase 1: Preparation (The "Push-Push" Start)
The algorithm starts by pushing the first two elements from Stack A to Stack B. This provides a base for comparison. From this point on, Stack B is kept sorted in descending order.

#### Phase 2: From A to B (The Greedy Search)

While there are more than 3 elements in Stack A, the algorithm performs the following:

1. Targeting: For each node in A, it finds its "target" in B. The target is the closest smaller number (e.g., if moving 10, the target in B is 9). If no smaller number exists, the target is the maximum value in B.

2. Cost Analysis: It calculates the number of operations required to bring the node to the top of A AND its target to the top of B.

3. Optimization (Synergy): If both the node and its target are on the same side of the median (both in the top half or both in the bottom half), we use combined rotations (rr or rrr) to move both stacks simultaneously, drastically reducing the operation count.

4. The Move: The "cheapest" node is selected and moved to B.

#### Phase 3: The Tiny Sort
When only 3 elements remain in Stack A, they are sorted using a hardcoded sort_three logic (maximum 2 moves). At this point, Stack B contains the bulk of the numbers in descending order.

#### Phase 4: From B to A (The Return)
Now, we push everything back from B to A.

1. Targeting: For the top element of B, we find its target in A (the closest larger number).

2. Execution: We rotate A to bring the target to the top and perform pa.

3. Repeat: This continues until Stack B is empty.

#### Phase 5: Final Alignment
Finally, the algorithm finds the smallest number in Stack A. If it’s not at the top, it performs a final series of rotations (ra or rra) to bring the minimum value to the first position, ensuring the stack is perfectly sorted.


## Instructions

### Compilation
The project includes a `Makefile` that compiles the `push_swap` executable. To compile, run:
```bash
make
```

### Execution
You can run the program by passing a list of integers as arguments. The numbers can be provided as separate arguments or as a single quoted string.

```bash
./push_swap 42 67 12 0 -5

./push_swap "42 67 12 0 -5"

ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')"); ./push_swap $ARG | wc -l

ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./checker_linux $ARG
```

### Technical choices
- Doubly Linked Lists: Used to represent stacks for O(1) insertions and deletions.

- Cost Calculation: The set_push_cost function evaluates whether to use rr or rrr based on whether the target node and the current node are both above or below the median.

- Memory Management: Implemented a robust free_matrix and free_stack system to ensure 0 memory leaks, even in error cases (MKO verified).

- Input Validation: Strict parsing to handle non-numeric input, integer overflows, and duplicate values.

## Resources

- The Turk Algorithm: Inspired by [A. Yigit’s approach.](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Linked List Data Structure](https://www.geeksforgeeks.org/dsa/linked-list-data-structure/)
- [push swap visualizer by o-reo](https://github.com/o-reo/push_swap_visualizer)
- [push swap tester by gemartin99](https://github.com/gemartin99/Push-Swap-Tester)

### Use of AI

- Refactoring: Assisting in condensing some functions to fit within the strict 25-line limit required by the 42 Norm.

- Documentation: Drafting this README and explaining the logic behind the "Turk" approach.
