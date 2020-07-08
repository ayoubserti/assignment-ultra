# Assignement 1

Use bit operator to calculate the sum of two integers, check overflow with bit operator too.

# Abstract

To implement `add` function using bitwise operators, I used a function template that check in compile-time
if the passed arguments are integers.

```
template<typename T>
typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type 
add(T a , T b)
...
```

And to prohibit the use with float types I specialize the template so it assert in compile-time

```
template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type 
add(T a , T b)
{
    static_assert(std::numeric_limits<T>::is_integer, "floating point not supported");
    return 0;
}
```

So calls like ```add ( 0.2548 , 152.6552)``` shoud assert in compile-time

*It's a header-only* program. include `add.h` to use it.

# Build

g++ -std=c++11 -o c1 main.cc -Werror

# Test

I provide main.cc as test program, it test some arbitrary values and check if the `add` function does 
correctly in corner-cases.

The test is based on function `assert()`. Therefore `test_add()`will print error message and abort the program

# Dev environment

I test it with clang/llvm for Xcode
```
$ g++ --version
Configured with: --prefix=/Applications/Xcode10.app/Contents/Developer/usr --with-gxx-include-dir=/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include/c++/4.2.1
Apple LLVM version 10.0.1 (clang-1001.0.46.3)
Target: x86_64-apple-darwin19.3.0
Thread model: posix
InstalledDir: /Applications/Xcode10.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
```