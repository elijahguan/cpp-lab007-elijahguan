#include "project/recursive_algorithms.h"

#include <stdexcept>
#include <utility>
#include <vector>
namespace {
    int binarySearchHelper(const std::vector<int>& array, int target, int left, int right) {
        if (left > right) {
            return -1; // Target not found
        }
        int mid = left + (right - left) / 2;
        if (array[mid] == target) {
            return mid; // Target found
        } 
        else if (array[mid] < target) {
            return binarySearchHelper(array, target, mid + 1, right); // Search in the right half
        } 
        else {
            return binarySearchHelper(array, target, left, mid - 1); // Search in the left half
        }
    }
}
namespace {
    void reverseArrayHelper(std::vector<int>& array, int left, int right) {
        if (left >= right) {
            return; // Base case: no more elements to swap
        }
        std::swap(array[left], array[right]); // Swap the elements
        reverseArrayHelper(array, left + 1, right - 1); // Recur for the remaining elements
    }
}
namespace {
    int arraySumHelper(const std::vector<int>& array, int index) {
        if (index >= array.size()) {
            return 0; // Base case: no more elements to sum
        }
        return array[index] + arraySumHelper(array, index + 1); // Recursive case
    }
}
// TODO: Implement factorial recursively.
// Base case: n == 0 or n == 1.
// Recursive case: n * factorial(n - 1).
int factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("Negative input not allowed for factorial");
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// TODO: Implement an iterative factorial comparison.
int factorialIterative(int n) {
    if (n < 0) {
        throw std::invalid_argument("Negative input not allowed for factorial");
    }
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// TODO: Implement fibonacci recursively.
// Base case: fib(0) = 0, fib(1) = 1.
// Recursive case: fib(n) = fib(n - 1) + fib(n - 2).
int fibonacci(int n) {
    if (n < 0) {
        throw std::invalid_argument("Negative input not allowed for fibonacci");
    }
    else if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// TODO: Implement iterative fibonacci comparison.
int fibonacciIterative(int n) {
    if (n < 0) {
        throw std::invalid_argument("Negative input not allowed for fibonacci");
    }
    else if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    int prev2 = 0;
    int prev1 = 1;
    int current;
    for (int i = 2; i <= n; ++i) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

// TODO: Implement recursive binary search on a sorted array.
// Base case: target not found or left > right.
// Recursive case: compare middle element and recurse on the appropriate half.
int binarySearch(const std::vector<int>& array, int target) {
    return binarySearchHelper(array, target, 0, array.size() - 1);
}

// TODO: Implement iterative binary search comparison.
int binarySearchIterative(const std::vector<int>& array, int target) {
    int left = 0;
    int right = array.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] == target) {
            return mid; // Target found
        } 
        else if (array[mid] < target) {
            left = mid + 1; // Search in the right half
        } 
        else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}

// TODO: Implement recursive array sum.
// Base case: empty array.
// Recursive case: first element + arraySum(rest-of-array).
int arraySum(const std::vector<int>& array) {
    return arraySumHelper(array, 0);
}

// TODO: Implement iterative array sum comparison.
int arraySumIterative(const std::vector<int>& array) {
    int sum = 0;
    for (int num : array) {
        sum += num;
    }
    return sum;
}

// TODO: Implement recursive in-place reversal.
// Base case: size <= 1.
// Recursive case: swap first and last elements, then recurse on the remaining middle.
void reverseArray(std::vector<int>& array) {
    reverseArrayHelper(array, 0, array.size() - 1);
}


// TODO: Implement iterative reverse comparison.
void reverseArrayIterative(std::vector<int>& array) {
    int i = 0;
    int j = array.size() - 1;
    while (i < j) {
        std::swap(array[i], array[j]);
        i++;
        j--;
    }
}
