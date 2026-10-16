# Recursive Algorithms Laboratory Notes

Students should implement each required function recursively, without using loops in the recursive versions.

## Required Algorithms

1. `factorial(n)`
-   The base case is to return 1 when n = 0 or n = 1 where n is the number of the factorial (ie n!). It will also return error for any n that is less than 0.
-   The recursive case is to return n * the factorial of n-1, and will recurse until n-1 = 1 or 0. 
-   The iterative version will keep a running product, iterate a loop all the way up to n, and multiply each number to the running product.
-   The time complexity is O(n) for both implementations.
-   The recursive version has O(n) space complexity because every recursive call adds a stack frame. The iterative version has O(1) space complexity because it only maintains a running product.
-   The number of recursive calls will change based on what n is. For example, if n is 3, it will have factorial(3), factorial(2), and factorial(1) = 1, so a total of n calls.
-   Using recursion will only add function-call overhead, but it is better than iterative in its simplicity.
-   There is a risk for stack overflow for some large number n, because the space complexity is O(n). However, the integer overflow error will most likely come first.
2. `fibonacci(n)`
-   The base case for this implementation is 0 when n = 0 and 1 when n = 1. If n is less than 0, there will be no possible number. In the recursive case, the input will be a number that is greater than or at least 2 (if n = 1 or 0 there will already be a base case). After taking in the number n, it will return the previous two values. If any of those two values are not known, it will continue recursing through the function until it reaches 0 and 1.
-   For the iterative case, the base cases are also defined. However, instead of calling a recursive function, it iterates via for loop, starting from i = 2 (since i=1 and i=0 are already known as the base cases). Iterating up to n, it constantly updates and shifts the current variables used to find the sum.
-   The recursive implementation has O(2^n) time complexity because it repeatedly calculates the same Fibonacci values. The iterative implementation has O(n) time complexity because it calculates every value from 2 through n once.
-   Space complexity: The recursive implementation has O(n) space complexity because its maximum call-stack depth is n. On the other hand, the iterative implementation has O(1) space complexity because it only maintains a fixed number of variables.
-   For the recursive function, the number and depth of recursive calls depends on the original value of n. A bigger n value would mean more recursive calls (as more values would need to be discovered). The calls grow exponentially because each call can branch out to two more calls. Recursion depth is O(n).
-   Both implementations are readable and maintainable. With the base cases, we don't need to worry about the recursive case running infinitely.
-   By using recursion, an advantage is code that is easier to read with fewer lines. Possible disadvantages include repeated work (calculating same value multiple times) and slower time and space complexity (possible stack overflow).
-   Stack overflow may occur when n becomes too large (space is O(n)), and integer overflow may also occur when the Fibonacci value at n is too large to hold.

3. `binarySearch(array, target)`
-   The base cases occur when the middle element equals the target or when left > right, meaning the target is absent. The recursive implementation does not use a while loop.
-   The recursive case involves checking for values and recursing through a smaller half of the sorted array if the current value is larger or smaller than the target.
-   If left is greater than right, the function will return -1 because it reached the base case.
-   The iterative version involves using a while loop and shifting the left and right indexes accordingly, instead of calling on the function multiple times.
-   Time complexity is O(log n) since we are cutting the list in half for each exploration. Space complexity is O(log n) for recursive as each call adds another stack frame. For iterative, space complexity is O(1).
-   The recursive calls will depend on the size of the array, but only recurses through a small amount because each call eliminates half of the remaining array. Its number of calls and recursion depth are O(log n).
-   The recursive version requires more calls and requires a helper function, but is a similar implementation to the iterative version.
-   Stack overflow is possible but unlikely due to the O(log n) space complexity.
4. `arraySum(array)`
-   The base case is if the array is empty, and will return 0. With the index helper, the base case will occur when the index equals to the size of the list.
-   The recursive case involves taking the first element and then adding that to the sum of the array where the starting index is at the next element.
-   The iterative version keeps a running sum and will iterate through the array, adding its values to the running sum.
-   The time complexity for both is O(n) as it involves traversing through the whole list.
-   There is no extra space allocated, so the space complexity for the iterative implementation is also constant O(1). For recursive, the space would be O(n) due to the number of calls it makes.
-   The amount of recursive calls depends on the size of the array. The recursive implementation works by adding the current index's element with the call of the helper at the next index.
- There is a stack overflow risk for a large array, since the space is O(n).
5. `reverseArray(array)`
-   The iterative implementation uses left and right to swap values while left < right. If there is one element, the indexes are equal, and if there is an empty list, both cases would not run.
-   The recursive implementation involves a helper function that does a similar check if the left index is the same or greater than the right index. If it is not, the indexes will swap and call itself with the indexes shifted.
-   The iterative solution is a simple O(n) where n is the total amount of elements. Even though the while loop only checks through half of the array, we can ignore negligible constants such as 1/2, therefore turning O(n/2) to O(n). The recursive solution is the same time complexity since the array is iterated through in a similar manner.
-   For space complexity, both arrays use std::swap and modify the array in-place. So, it is O(1), constant time complexity. However, for recursive, it is O(n) since each call adds to the stack frame
-   The number of recursive calls is always n/2, since the recursion will stop once the left index is either equal to or greater than the right index.
-   Both functions are readable and maintainable.
-   Advantages of recursion is the short one-liner in the main function, at the cost of higher function-call overhead and the need for a helper function separately defined.
-   There is still stack overflow risk even though the calls only iterate n/2 times. This is because the recursion depth is still O(n) and will overflow for a large array size.

## Expected Design

- Identify and comment on the base case for each implementation.
- Identify and comment on the recursive case for each implementation.
- Use clear parameter names and return values.
- Include validation for invalid or unsupported inputs.
- For comparison, also implement iterative versions.

## Comparison Requirement

For each algorithm where an iterative solution is reasonable, provide a written comparison covering:

- time complexity;
- space complexity;
- number and depth of recursive calls;
- readability and maintainability;
- advantages and disadvantages of recursion;
- stack overflow risk;
- Big-Oh analysis for both recursive and iterative forms.
