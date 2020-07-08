# Assignement 2

Given an integer (T) and an integer set (I), find a subset (M) that the sum (S) of M's elements is the largest among all subsets of I. S <= T.
Signature of the interface : 

```
void find_largest_sum(​uint32_t​ T, const std::vector<​uint32_t​> &I, vector<​uint32_t​>& M, ​uint32_t​ &S);
```


example
T: 11
I: 1 , 2, 3, 4, 5, 6,7
possible answers M: 5,6
S:11
M: 4, 7 S: 11


# Abstract

 It's similar to a `Knapsack problem` with the particularity that all elements has same importance ( weight)
 The intuitive and no-optimal solution is to use Greedy algorithm 
 ```
    sort objects in descending order of efficiency
    w_conso := 0

    for i de 1 à n
    if w[i] + w_conso ≤ W then
        x[i] := 1
        w_conso := w_conso + w[i]
    else
        x[i] := 0
    end if
    end for
 ```



# Build

g++ -std=c++11 -o assign main.cc -Werror

# Test

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