list operations like python
- negative indexes point to end of list
- range substring operators like 1:4
- ```[-1] [1:4]```

range operator
- 1...10 -> list of integers from 1 to 10
- 1,1.5,...10 -> list of floats from 1 to 10 increasing by 0.5
- 1,...,9.5,10 -> same as last

for loops
- for int i in 1...10
- for i := 0; {conditional}; {incrementer}
- for int i in list

initialization denoted like in go
- := for initial variables
- = for setting the contents of a variable

nil coalescence
- {var} ?? {default value if undefined}
- equivalent to {var} ? {var} : {default value if undefined}

undefined, not null
- 'undefined' refers to variables that don't have any value

nothing abbreviated
- 'function', 'structure', 'boolean', 'string', makes code more readable

return types defined with support for tuples
- function {function name}({parameters}) ({return types})
- means 'a, b = test()' is valid if test returns '({type}, {type})'

no try, catch blocks
```
f, err := input();
if err { panic(err); }
```

curly brace structure, forced semicolons

something equals this or that shorthand
```
{value} == {value2} or is {value3} or is {value4}
// equivalent to
{value} == {value2} or {value} == {value3} or {value} == {value4}

// and so is
{value} == {value2} and is {value3} and is {value4}
// equivalent to
{value} == {value2} and {value} == {value3} and {value} == {value4}
```

built in 'in' keyword for arrays
```
if {value} in {array}
```

comparison operators spelled out except for bitwise (also more logical operators
```
and, or, not, implies, xor
&, |, ^, <<, >>, ~
```

spread operator
...kwargs
