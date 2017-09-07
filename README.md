# C++ Cleaner

C++ Cleaner replaces comments, string literals, and character literals in an
input C++ program with dummy values. The original intention was to remove parts
of a program that could accidentally be interpreted as code by automated tools
that check for code style. At the same time, another goal was to preserve the
number of lines and the length of each line, allowing such automated tools to
run on the "cleaned" program and still provide useful output.

To run C++ Cleaner, you must have Python 2 on your path. If `input.cpp` is the
C++ file to be cleaned, then the following command prints the "cleaned" program
to standard output:

    $ python clean.py < input.cpp

The software makes the following assumptions:
* The input program is a valid C++ program in C++11 or earlier.
* The input program does not contain any trigraphs.
* The only characters in the input program are the ASCII characters 1 through
  126, as described at <http://www.asciitable.com/>.

C++ Cleaner treats backslash + whitespace + newline as a continuation of the
current line of code, even though the C++ standard only requires backslash +
newline to continue the current line. Similarly, C++ Cleaner considers carriage
return to be a whitespace character, even though it is not part of the basic
source character set. The motivation for both of these decisions is that both
`g++` and `clang` provide this behavior, and C++ Cleaner is probably more
useful if it conforms to the behavior of these two major compilers.
