# Binary Search - Aditya Verma YouTube Course

This repository contains notes and implementations from **Aditya Verma's Binary Search playlist** on YouTube, covering various Binary Search patterns and problems.

## 📚 Course Overview

Binary Search is a fundamental algorithm with time complexity O(log n) that works on sorted arrays. This course covers everything from basics to advanced Binary Search variations.

## 🎯 Topics Covered

### Lecture 01: Introduction to Binary Search
- **Basic Binary Search**
  - Array needs to be sorted - "Think of the BS"
  - Fundamental concept and approach

### Lecture 02: Mid Calculation Techniques
- Two methods for calculating mid:
  1. `mid = (high + low) / 2`
  2. `mid = start + (end - start) / 2` *(Prevents overflow)*

**Basic Binary Search Implementation:**
```cpp
int binarySearch(vector<int>& arr, int target)
{ 
    int low = 0;
    int high = arr.size() - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return -1;
}
```

### Lecture 03: Binary Search in Reverse Order
- **Reverse Sorted Array**
  - Adjust conditions according to descending order

### Lecture 04: Find First and Last Position of Element
- **Problem:** Find First and Last Position of Element in Sorted Array
- **Example 1:**
  - Input: `nums = [5,7,7,8,8,10]`, `target = 8`
  - Output: `[3,4]`
- **Example 2:**
  - Input: `nums = [5,7,7,8,8,10]`, `target = 6`
  - Output: `[-1,-1]`

### Lecture 06: Find Minimum in Rotated Sorted Array
- **Approach:** Compare mid element with its previous and next neighbors
- Identify the rotation point

### Lecture 07: Search in Rotated Sorted Array
- **Strategy:**
  - Find the pivot index
  - Perform Binary Search in both segments
  - `BS(0, pivot - 1)` and `BS(pivot, end)`

### Lecture 08: Search in Nearly Sorted Array
- **Difference from Normal BS:**
  - Normal BS: Check only `mid`
  - Nearly Sorted: Check `(mid - 1)`, `mid`, `(mid + 1)`
  - Iterate with `-2` and `+2` adjustments

### Lecture 09: Floor of an Element
- **Finding the Floor:**
  1. If key exists → return key
  2. If key doesn't exist → return greatest element less than key
  3. If less than `arr[0]` → return -1

### Lecture 10: Ceiling of an Element
- **Finding the Ceiling:**
  1. If key exists → return key
  2. If key doesn't exist → return smallest element greater than key
  3. If greater than `arr[n-1]` → return -1

### Lecture 11: Next Alphabetical Character
- **Problem:** Find the next alphabet
  - Strictly next alphabet (not equal)

### Lecture 12: Search in Infinite Sorted Array
- **Challenge:** Array is infinitely sorted
- **Extra Step:** Find the limit/range over the array first
- Use exponential search to find bounds

### Lecture 13: First Occurrence of 1 in Binary Array
- **Problem:** Find the first occurrence of 1 in a binary sorted array
- Get the limit range where the first 1 will occur

### Lecture 14: Minimum Difference Element in Sorted Array
- **Approach:**
  - If element is present → return that element
  - If not present → BS pointers (high and low) will point to respective positions
  - Return minimum difference possible

### Lecture 15: Binary Search on Answer
- **Concept:** Reduce the search space by 2 each time
- Reform the conditions in such a way to apply BS
- Example: Peak element

### Lecture 16: Peak Element
- **Problem:** Find peak element in an unsorted array and return its index
- **Edge Cases:** Check at 0th and (n-1)th positions
- A peak element is greater than its neighbors

### Lecture 17: Search in Bitonic Array
- **Approach:**
  - Find peak element first
  - Perform BS in two separate arrays:
    - `(0 to peak)` - ascending part
    - `(peak + 1 to end)` - descending part

### Lecture 18: Search in Row-wise and Column-wise Sorted Matrix
- **2D Matrix Search**
- Matrix is sorted both row-wise and column-wise
```
| 1  10  20  30  |
| 3  12  22  34  |
| 5  15  23  45  |
| 8  19  25  90  |
```

## 🔗 Resources

- **YouTube Playlist:** [Aditya Verma - Binary Search](https://www.youtube.com/playlist?list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2)
- **Implementation:** [BinarySearch_byAdi_V.cpp](BinarySearch_byAdi_V.cpp)

## 📝 Notes

- Always ensure the array is sorted before applying Binary Search
- Use `mid = start + (end - start) / 2` to prevent integer overflow
- Identify the pattern in the problem to apply the correct variation
- Practice identifying when to use Binary Search on answers

## 🚀 Key Takeaways

1. **Standard Binary Search:** Works on sorted arrays
2. **Modified Conditions:** Adjust for reverse sorted, rotated, or nearly sorted arrays
3. **Binary Search on Answer:** Apply BS to reduce search space even when array isn't sorted
4. **2D Arrays:** Extend BS concepts to matrix problems

---

**Happy Coding! 🎯**
