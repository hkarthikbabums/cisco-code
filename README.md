Cisco Coding Excercise
Problem Description with Outputs
1->4->5->+->5->NULL

The design is to come up with a linked list as above and treat the values before an operator as 
first operand by concatenating them and the values after the operator hit as second operand, 
then evaluate the first operand and second operand based on the received arithmetic operator.

Positive:

1->4->5->+->5->NULL

145 concatenated to become the first operand
+ is the arithmetic operator 
5 is concatenated second operand

Output of the code:

Equation: 145+5
The Success Value is: 150
Result: 0 >> this is enum value for the success

Negative:

1->4->5->+->NULL

145 concatenated to become the first operand
+ is the arithmetic operator 
There is no second operand to perform the opertation, hence asked to return error

Equation: 145+
No second operand present
Result: -1 >> this is enum value for the failure

Limitation: 

This works only for char value as the linked list element value.
