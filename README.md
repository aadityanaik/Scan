# Scan
A class similar to Java's Scanner class which verifies user input

# Usage
Copy the class into your source file.<br/>
The class throws an exception if a wrong input is given, so the user must implement exception handling.

# Note
This class is strict on type-checking, so if the user is expecting an integer using<br/>
```
Scan input;
int x;

x = input.get<int>();
```
but a double is entered, the class will throw an exception.
