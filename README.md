# Sudoku Solver
# Overview

This software is designed to take a sudoku puzzle and solve it.

The program accomplishes this by looking at each individual square and eliminating options based on what is in the row, column, and box. If there is only one option then it will replace the blank square with the correct number. If no solution is found it will continue looking at all of the other squares. The program will loop through the puzzle until it is complete. This isn't a fool-proof way to solve puzzles but it will solve easy-medium puzzles.

My purpose for writing this software was to learn and demonstrate proficiancy in the C++ programming languague.

{Provide a link to your YouTube demonstration.  It should be a 4-5 minute demo of the software running and a walkthrough of the code.  Focus should be on sharing what you learned about the language syntax.}

[Software Demo Video](http://youtube.link.goes.here)

# Development Environment

I used visual studio code as my IDE.

This program is written in the C++ language. I didn't use any libraries but did include commonly used STL's such as vector and map.


# Useful Websites

{Make a list of websites that you found helpful in this project}
* [W3Schools](https://www.w3schools.com/cpp/)
* [Stack Overflow](https://stackoverflow.com/)
* [C++](https://cplusplus.com/doc/tutorial/arrays/)
* [Tutorials Point](https://www.tutorialspoint.com/cplusplus/index.htm)

# Future Work

* Let the user type the filename of the puzzle.
* Create a more fool-proof way to solve puzzles that cannot be solved by the process of elimination.
