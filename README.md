
# Incubyte Assignment
The code is written in C++ and works for the mandatory 6 test cases mentioned in the problem statement.

1. The method can take numbers as a string separated by comma and will return their sum (for anempty string, it will return 0).

Approach: 
- Used getline function to input the string so that we can input an empty string.
- Traverse the part of the string between ',' and ignore the ','
- stoi() method is used to convert string to integer.
- The integer is the pushed into a vector in order to take the sum.

2. Allow the add method to handle an unknown amount of numbers.
3. 
Approach: 
- The traversal will go on for the size of the input string.

3. Allow alphabets to be included with numbers.
The numeric value for the alphabet would be equal to its position.
Such as a = 1, b = 2, c = 3 … y = 25, z = 26. Note: Use lowercase alphabets only.

Approach: 

- (s[i]-'a') gives us the difference between the ASCII values of the letters and ((s[i]-'a') + 1) gives there position in the alphabets.

4. Calling add with a negative number will throw an exception “Negatives not allowed” - and the negative
that was passed.

Approach: 
- In the exception catch we push the negative numbers into another vector, so that all negative numbers can be stored together in order to output.

5. If there are multiple negatives, show all of them in the exception message

Approach: 
- Use to_string() method to concatenate all negative numbers into a string and display it with exception message.


6. Numbers bigger than 1000 should be ignored.

Approach: 
- While pushing the number into the numbers vector we check this condition.

P.S: I did all the trial and debugging on my end and have uploaded the optimized code on the repository. Hence have mentioned the approach for each problem statement here.
