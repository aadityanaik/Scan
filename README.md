# Scan
A class similar to Java's Scanner class which verifies user input.<br/>

# Installing
Add the class file (scan.hpp) into your include path. There is no need to build the file, since all the functions are defined in the class file itself.<br/>

# Features-
Verifies the input and throws an exception if not matching.<br/>
Uses strict type checking to ensure that doubles and integers are not interchanged.<br/>
Takes care of the buffer clearing whenever wrong datatypes are entered.<br/>

# Note
This class is strict on type-checking, so if the user is expecting an integer using<br/>
```
Scan input;
int x;

x = input.get<int>();
```
but a double is entered, the class will throw an exception. The same applies for the Scanner::next<type>() function.<br/>
<br/>
It is preferrable to use the Scanner::next<type>() function to avoid unnecessary try blocks-<br/>
```
int x;

x = Scanner::next<int>("Integer expected");
// This gives "Integer expected" as the error message and
// keeps accepting inputs till it encounters an integer

x = Scanner::next<int>();
// This prints out the default message "Invalid datatype entered" as the error

// All error messages are printed to stderr
```
<br/>
<br/>

![Demo](screenshots/screenshot.png?raw=true "Demo")
