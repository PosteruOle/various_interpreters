# Various interpeters
This repository contains the list of interpreters created during the Translation of Programming Languages course at the Faculty of Mathematics, University of Belgrade.

This repository contains the following colection of interpreters:
- assembly generator
- finite_automata - it's not actually a intepreter, but that's a concept alse presented throughout the course;
- graph_operations
- matrix - its an interpreter that is able to process commands for the creation of matrices and commands for applying well-known operations on created matrices
- polynomials - its an interpreter that is able to process commands for the creation of polynomials and commands for applying well-known operations on created polynomials

Here are some of the commands we would like to process and execute:
```
<1, -3, 0, -1, 6>
<1, 2, 1, 2> + <0, -1, 3>
<1, 2, 1, 2> - <0, -1, 3>
<1, 2, 1, 2> * <0, -1, 3>
- <0, -1, 3>
p1 := <1, 2, 1, 2>
p2 := <0, -1, 3>
p1 * p2
p3 := (p1-p2)*<1>
p3
p1 == <1,2,3>
p1 != p2

//p1'
(p1+p2)'- <1, 1>'
//$p1|3
//$p1+p2|2.3
//<1, 2> + $p1+p2|2.3
//p1[1]
//(p1+p2)[0]
```
- set_operations - its an interpreter that is able to process commands for the creation of sets and commands for applying well-known operations on created sets
Here are some of the commands we would like to process and execute:
```
A := {1, 2, 3, 4, 6};
B:={2, 4, 6, 8, 10};
print A;
print B;
print_ALL;
print A \/ B;
print A /\ B;
print A \ B;
print A <> B;
check 5 : A;
C:= 5..10;
D:= B\/C;
print C;

print D;

UniversalSet:={1,2,3,4,5,6,7,8,9,10};
card A;
print ~A;
A:=~A;
card A;
check A < B;
```
  
- stacks_n_queues
