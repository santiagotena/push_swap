# push_swap
 
<p align="center">
<img src="https://github.com/santiagotena/assets/blob/master/logos/42%20logo.jpeg?raw=true" alt="42 Wolfsburg Logo" width="150" height="150">
</p>
 
Push_swap is a 42 Wolfsburg number sorting algorithm project. Given a set of integer values that are given as input and having two stacks at our disposal. We are to produce the smallest set of instructions we can that will manipulate both stacks and end up ordering the numbers in ascending value in one of the stacks.
 
A core concept for this kind of project is that of algorithm complexity. Different algorithms perform at differing efficiencies in terms of actions and time.
 
## Rules
 
### Starting conditions:
 
We have 2 stacks. Stack a and stack b.
 
The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated. In addition, the stack b is empty.
 
### Objective:
 
Sort the numbers in ascending order into stack a. 
 
### Available actions:
 
<ul>
<li> sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. </li>
<li> sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements. </li>
<li> ss : sa and sb at the same time. </li>
<li> pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty. </li>
<li> pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty. </li>
<li> ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one. </li>
<li> rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one. </li>
<li> rr : ra and rb at the same time. </li>
<li> rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one. </li>
<li> rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one. </li>
<li> rrr : rra and rrb at the same time. </li>
</ul>
 
In case of error, the program must display "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments are not integers, some arguments are
bigger than an integer and/or there are duplicates.
 
# Usage
 
Use `make` to compile the program.
 
Feed a list of unsorted integers to the program:
 
```
./push_swap <numbers>
```
 
# Example
 
Input:
 
```
./push_swap 99 77 123 55 -87 -42
```
 
Output:
 
```
Start
A Stack:
val     ind     pos     tp      ca      cb
99      5       0       0       0       0
77      4       0       0       0       0
123     6       0       0       0       0
55      3       0       0       0       0
-87     1       0       0       0       0
-42     2       0       0       0       0
 
B Stack:
 
ra
ra
ra
pb
pb
pb
sa
pa
pa
ra
ra
pa
rra
rra
 
End
A Stack:
val     ind     pos     tp      ca      cb
-87     1       0       0       0       0
-42     2       1       0       0       0
55      3       0       2       2       0
77      4       2       0       0       0
99      5       3       0       0       0
123     6       4       0       0       0
 
B Stack:
```
