Solving the UVa Online Judge problem "673 - Parentheses Balance" involves checking if a given string of parentheses is balanced or not. Here's a basic approach to solving this problem:

**Problem Description:**
You are given a string containing only parentheses ('(' and ')'). Your task is to determine if the parentheses are balanced, meaning for every open parenthesis '(', there is a matching closing parenthesis ')'.

**Algorithm:**

1. Initialize an empty stack (you can use a data structure like a list or a stack in Python).
2. Iterate through each character in the input string from left to right.
3. For each character:
   - If it's an open parenthesis '(', push it onto the stack.
   - If it's a closing parenthesis ')', check if the stack is empty:
     - If it's empty, return "No" because there is no matching open parenthesis.
     - If the stack is not empty, pop the top element from the stack.
4. After processing the entire string, check if the stack is empty:
   - If it's empty, return "Yes" because all parentheses are balanced.
   - If it's not empty, return "No" because there are unmatched open parentheses.

**Python Code:**

Here's a Python implementation of the above algorithm:

```python
def is_balanced(parentheses):
    stack = []

    for char in parentheses:
        if char == '(':
            stack.append('(')
        elif char == ')':
            if not stack:
                return "No"
            else:
                stack.pop()

    if not stack:
        return "Yes"
    else:
        return "No"

# Read input and process each test case
num_cases = int(input())
input()

for _ in range(num_cases):
    parentheses = input().strip()
    result = is_balanced(parentheses)
    print(result)

```

**Explanation:**
- We read the number of test cases first and then process each test case.
- The `is_balanced` function checks if the parentheses in a given string are balanced using the stack-based approach.
- We print "Yes" if the parentheses are balanced and "No" otherwise.

This code should solve the "673 - Parentheses Balance" problem on UVa Online Judge. Make sure to handle multiple test cases as shown in the code, and it should work correctly.