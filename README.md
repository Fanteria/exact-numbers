# Exact numbers

This repository contains C++ implementation of fractions. Implementation is a fun project and is not production-ready, so don't use it in your project if you want to have exact numbers, if you want to use exact numbers, you can use [this](https://www.boost.org/doc/libs/1_43_0/libs/rational/rational.html) boost library (_or implements your owns for sure_).

If you still want to check this repository, then I describe the basics for you below.

## Usage

After the start of the program you will be asked "What do you want to do?", you can use operators `+`, `-`, `*` and `/` for two numbers. You can also save that expression to a variable by `name_of_variable = ` and expression.

For variables, you can use previous operators and logic operators `<`, `<=`, `>`, `>=`, `==` and `!=`. The result of a logical expression cannot be stored in a variable. The result of others can.

If you want to exit from the program simply write "exit".

## Implementation

The project contains two classes. Class `ExactNumber` implements only numbers and operators for them. Numbers are implemented as fractions and after every operation are that fractions are minimized per GCD (_greatest common divisor_).

Class `Calculator` implements a command-line program for users and stores variables.

## Conclusion

First, I'm sorry for my crappy English. Second, as I write above, this is a fun project that cannot be used in production code. There are lots of parts that can be implemented better. For example find GCD can be implemented by GCC build-in function that significantly speeds up finding of GCD, if you are interested in that, you can check [this](https://lemire.me/blog/2013/12/26/fastest-way-to-compute-the-greatest-common-divisor/) post.
