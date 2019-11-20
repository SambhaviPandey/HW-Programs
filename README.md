# turtleprogram
Turtle Graphics as part of [Logo](https://en.wikipedia.org/wiki/Logo_(programming_language) 
was one of the first languages explicitly designed for teaching beginning programming.

A Turtle Program is a set of instructions directing the on-screen turtle to draw graphics. 
To draw a square, one would execute:
```
Forward 10 Right 90 Forward 10 Right 90 Forward 10 Right 90 Forward 10 Right 90
```

Other commands, such as PENUP, PENDOWN, PENCOLOR, etc, 
as well as conditionals and looping operators were later added to the language.

There should be no warnings when compiled with `-Wall -Wextra -Wno-sign-compare`
`clang-tidy turtleprogram.cpp -- -std=c++14` should not give any warnings. 
No warnings are given when travis-ci tests this program by doing:
clang++ -std=c++14 -Wall -Wextra -Wno-sign-compare *.cpp -g -o myprogram

You can modify `.clang-tidy` as long as each modification is explained in README.md
(and you do not disable all checks)
`valgrind ./ass1_turtleprogram` should not have any `definitely lost` bytes. You might
still have `indirectly lost`, `possibly lost` or `still reachable` bytes due
to libraries used.
 

## Included Files

- `CMakeLists.txt`: For complex projects, `cmake CMakeLists.txt` will
  generate a `Makefile`. We can then use `make` to compile the
  project. 

- `turtleprogram.cpp`: Definitions for turtle functions.
   The first constructor is not written as 
   TurtleProgram::TurtleProgram() { 
   } 
   But is written as: TurtleProgram::TurtleProgram() = default;
   The reason for this is because travis-ci stated that '= default'
   should be used to define a default constructor. 

- `turtleprogramtest.cpp`: Test functions to test turtle. Additional tests
   are added to further test the functions.
   
   In Linux lab, enabling: 
   #pragma clang diagnostic push,
   #pragma clang diagnostic ignored "-Wself-assign-overloaded",     
   #pragma clang diagnostic pop
   resulted in warnings being issued while building the CXX objects 
   (after doing 'make' to compile the project). Commenting the above 
   (#pragma lines of code) in the turtleprogramtest.cpp eliminated the 
   warnings. 
   However, the above (#pragma lines of code) are needed 
   when running it on travis-ci.

- `main.cpp`: A generic main file to call testAll() to run all tests

- `output.txt`: Output from `./simple.compile.sh > output.txt 2>&1`
   showing how the program is compiled and run

- `simplecompile.sh`: Unix bash script file to compile, run clang-tidy
  as well as other programs and then delete the executable. Can be
  used to create an output.txt file

- `.clang-tidy`: Specify the options for clang-tidy program, so we do
  not have to enter them on the command line each time.
  Usage: `clang-tidy *.cpp -- -std=c++14`

  clang-tidy issued a warning when a string array was created in the 
  following manner: 
  string *temporaryArray = new string[length + Tp.getLength()];
  clang-tidy stated that string should be changed to auto in order
  avoid duplicating the type name. Thus, in many functions in 
  turtleprogram.cpp a string array is created by doing:
  auto *TemporaryArray = new string[length + Tp.getLength()];

  On travis-ci (but not on linux lab), clang-tidy issues a 
  [performance-unnecessary-copy-initialization] warning for 
  the already written tests provided by the professor. This
  warning is issued because the local copy of the variable is 
  never modified so clang-tidy states that you have to consider
  avoiding the copy. However, this warning is not applicable for 
  this program because the tests written in this program are meant to be 
  used to test the copy constructor. 

- `.gitattributes`: Options for git. Making sure that simplecompile.sh
  always has the correct line endings when moving between Windows and
  unix systems

- `.gitignore`: Files that should not be checked into git. Mostly ide
  files and executables.

- `.travis.yml`: When GitHub is configured correctly, checking the
  project into GitHub should trigger Travis CI to compile and run the
  program.

## Compile and Run

```
cmake CmakeLists.txt
make
./ass1-turtleprogram
```

or

```
clang++ -std=c++14 -Wall -Wextra *.cpp -o ass1-turtleprogram
./ass1-turtleprogram
```

## Style check

```
clang-tidy *.cpp -- -std=c++14
```

### Style Explanation
These options are defined in `.clang-tidy` file.

Perform all check except the following:

- cppcoreguidelines-pro-bounds-array-to-pointer-decay: do not give warnings on assert
- google-build-using-namespace: for simplicity allow `using namespace std;`
- google-readability-braces-around-statements: allow compact code without `{`
- readability-braces-around-statements: allow compact code without `{` (this option
is not available in CSS Linux lab under LLVM 3.8.1, but is needed on my PC when using
9.0.0)
- hicpp-no-array-decay: allow assert
- modernize-use-trailing-return-type: not ready for auto func() -> int format yet
- hicpp-braces-around-statements: want compact code
- cppcoreguidelines-pro-bounds-pointer-arithmetic: need to use array indexes
- llvm-header-guard: header guards do not have full directory name
- google-global-names-in-headers: OK to say `using namespace std;` for class code
- cppcoreguidelines-special-member-functions: no move constructor or move assignment for now
- hicpp-special-member-functions: no move constructor or move assignment for now
- cppcoreguidelines-owning-memory: not using gsl, so assigning new owners



Based on LLVM style in https://llvm.org/docs/CodingStandards.html#the-low-level-issues

```
CheckOptions:
 - { key: readability-identifier-naming.ClassCase,           value: CamelCase  }
 - { key: readability-identifier-naming.StructCase,          value: CamelCase  }
 - { key: readability-identifier-naming.EnumCase,            value: CamelCase  }
 - { key: readability-identifier-naming.VariableCase,        value: CamelCase  }
 - { key: readability-identifier-naming.GlobalConstantCase,  value: UPPER_CASE }
 - { key: readability-identifier-naming.FunctionCase,        value: camelBack  }
 - { key: readability-identifier-naming.PublicMethodCase,    value: camelBack  }
 - { key: readability-identifier-naming.PrivateMethodCase,   value: camelBack  }
 - { key: readability-identifier-naming.PublicMemberCase,    value: CamelCase  } 
```

## Misc

This files is part of a repository located at
https://github.com/pisan343/ass1-turtleprogram BUT most students will use it as
the starting code for GitHub Classroom exercise

When using via GitHub Classroom, the Travis CI output will be at

https://travis-ci.com/uwbclass/ass1-turtleprogram-GitHubUserName
