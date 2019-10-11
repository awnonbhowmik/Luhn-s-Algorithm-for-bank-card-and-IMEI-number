# Luhn's Algorithm for checksum validation
This program takes reads in a number, doubles every other number starting from the second rightmost towards left. Turns the double digit numbers in the new string of numbers into single digits. If the sum of the new string is divisible by 10, then the original number is valid, else invalid. This is why this method is also known as "Mod 10" method. With a little modification, the same program can be used to calculate the check digit of a valid number.

This simple program can be employed to detect credit card frauds and faulty IMEI numbers.

# Checksum Algorithm
  - Read in a number n
  - Start from the second rightmost number, and double every other number working towards left
  - If doubling results in a two digit number, then add the digits of that number to turn it into a single digit number
  - Add the new numbers in the string
  - If the sum of the new numbers is divisible by 10, the number is valid

# Check Digit Algorithm
  - Read in a number n
  - Start from the rightmost number, and double every other number working towards left
  - If doubling results in a two digit number, then add the digits of that number to turn it into a single digit number
  - Add the new numbers in the string
  - Subtract that sum from the nearest multiple of 10, to get the check digit
