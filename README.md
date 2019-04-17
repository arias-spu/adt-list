# Implementation of Abstract Data Type List: Variable Size Array List

## Purpose
The goal of this lab is to implement class VSArray.

## Design
Class `VSArray` is a subclass of `List`, and it implements all virtual
pure methods from class `List`. The difference between this class and 
FSArrayList is that this class allows the array to grow if `_size == _capacity`.

You are expected to grow the size of the array by 50% just like it was
discussed in class.

## What is given?
The code for the abstract class `List`, the code for `FSArray`, the modified unit test,
the makefile (if you wish to use it).

## What is expected?
- Your code ***must*** compile.
- Your grade will be *almost* the percentage of your passed unit tests.
- Your code needs to show good programming practices: indentation, meaningful 
variable names, identifiers convention (CamelCase for functions, camelCase 
for variables, _camelCase for data members, SNAKE_CASE for constants), 
header comments, correct file names, etc. Failure to code appropriate will 
result in strong points penalization.
