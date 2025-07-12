# 🧮 Various Interpreters  
**Course Project – Translation of Programming Languages**  
*Faculty of Mathematics, University of Belgrade*

---

## 📚 Overview

This repository contains a collection of interpreters developed as part of the **Translation of Programming Languages** course. Each interpreter focuses on a different data structure or mathematical concept, demonstrating how simple domain-specific languages (DSLs) can be created and parsed.

---

## 🗂 Included Interpreters

### 🔧 `assembly_generator/`
- Basic assembler code generator created during the course.

### 🔄 `finite_automata/`
- **Note**: Not an interpreter, but an important concept covered during the course involving automaton design and simulation.

### 📊 `graph_operations/`
- Handles operations and transformations on graph structures.

### ➗ `matrix/`
- Interpreter for matrix manipulation.  
- Supports matrix creation and standard operations like addition, subtraction, and multiplication.

### 📐 `polynomials/`
- Interpreter for polynomial expressions.  
- Supports:
  - Polynomial creation
  - Arithmetic operations (+, −, *)
  - Derivatives
  - Evaluation
  - Equality checks
  - Indexing

**Example commands**:
```txt
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
(p1+p2)'- <1, 1>'

// p1'
// $p1|3
// $p1+p2|2.3
// <1, 2> + $p1+p2|2.3
// p1[1]
// (p1+p2)[0]
```

### 🧮 `set_operations/`
- Interpreter for working with mathematical sets.  
- Supports:
  - Set creation
  - Union, intersection, difference
  - Complement
  - Membership and subset checks
  - Cardinality

**Example commands**:
```txt
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

### 📦 `stacks_n_queues/`
- Interpreter for stacks and queues.  
- Supports creating and manipulating stack/queue structures using basic commands.

---

## 📌 Summary

Each interpreter is built to recognize and process custom syntax, offering insights into how compilers and interpreters work behind the scenes. This project serves both as an educational tool and as a base for more complex language design experiments.

---
