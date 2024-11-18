# Credit-Card-Number-Authenticator
Determines whether an inputted credit card number is acceptable using Luhn's Algorithm.

Luhn Algorithm is a way to test the validity of a credit card number. It:
1. Double every second number from right to left
2. Sum up all individual digits from Step 1
3. Add all odd numbered digits from right to left
4. Sum up Steps 2 and 3 results
5. If Step 4 result is divisible evenly by 10, it is valid

This program uses Luhn's Algorithm to test the validity of inputted credit card numbers. It will also check if the input contains letters and also if it contains exactly 16 characters.
