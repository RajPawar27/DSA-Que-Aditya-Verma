# Sliding Window - Aditya Verma

## Introduction

### What is Sliding Window?

The Sliding Window technique is used when dealing with:
- **Array/String** problems
- **SubArray/SubString** operations (with or without fixed size)
- **Related queries** on contiguous elements

### Types of Sliding Window

1. **Fixed Window** - Window size is constant (given as `k`)
2. **Variable Window** - Window size changes based on a condition

### Window Size Calculation

For a window from index `i` to `j`:

```
arr[] = { 1, 34, 53, 52, 76, 34, 12 }
          i           j
          1           4

Window Size = (j - i + 1) = 4 - 1 + 1 = 4
```

---

## Fixed Window Problems

### 1. Maximum Sum Subarray of Size K (Lecture 03)

**Problem**: Find the maximum sum of any subarray of size `k`.

**Input**: `arr[n]`, `int k`

---

### 2. First Negative Number in Every Window of Size K (Lecture 04)

**Problem**: For each window of size `k`, find the first negative number.

---

### 3. Count Occurrences of Anagrams (Lecture 05)

**Problem**: Count how many anagrams of a pattern exist in a text.

**Example**:
```
str1[m] = "[for]xxst[rof]gfsxw[ofr]"  (m > n)
str2[n] = "for"

Result: 3
```

The pattern "for" appears as anagrams in 3 places.

---

### 4. Maximum of All Subarrays of Size K (Lecture 06)

**Problem**: Find the maximum element in each subarray of size `k`.

**Example**:
```
arr[] = { 1, 3, 2, 1, 7, 3 }, k = 3
```

**Approaches**:
1. **Brute Force** - Time: O(n × n × k)
2. **Max Heap (Priority Queue)** - Better performance
3. **Deque** - Optimal approach
   - Prepare queue from index `0` to `k-1`
   - Maintain actual maximum element
   - Slide the window to the end while adding new elements and maintaining max

---

## Variable Window Problems

### Introduction (Lecture 07)

In variable window problems, the window size changes dynamically based on a condition.

---

### 5. Longest Subarray with Sum K (Lecture 08)

**Problem**: Find the maximum length of a subarray with sum equal to `k`.

**Approaches**:
1. **Brute Force** - Time: O(n²)
2. **Prefix Sum HashMap** - Can handle negative elements
3. **Sliding Window** - Optimal for non-negative integers only
   - Adjust window based on condition: `currentSum >=< k`

---

### General Format for Variable Window (Lecture 09)

```cpp
while(j < size)
{
    // Include calculation for j
    
    if(condition < k) 
    {
        j++;
    }
    else if(condition == k)
    {
        ans = max(ans, j - i + 1); // or other calculation
        j++;
    }
    else if(condition > k)
    {
        while(condition > k)
        {
            // Remove calculation from i-th element
            i++;
        }
        j++;
    }
}
```

---

### 6. Longest Substring with K Unique Characters (Lecture 10)

**Problem**: Find the length of the longest substring with exactly `k` unique characters.

**Data Structure**: HashMap `<char, int>` to track character frequency

**Structure**:
```
1. Include element at j
2. Shrink window from i (remove when frequency == 0)
3. Check if map.size() == k, then update answer
```

---

### 7. Longest Substring with All Unique Characters (Lecture 11)

**Problem**: Find the length of the longest substring where all characters are unique.

**Key Insight**: Here `k` is equivalent to the window size itself
- `k <==> (j - i + 1)`

**Structure**:
```
1. Include element at j
2. Shrink window from i (remove when frequency == 0)
3. Compare answer with current window size
   (At this level, map contains only unique elements)
```

---

### 8. Pick Toys (Lecture 12)

**Problem Interpretation**: Largest subarray with unique elements = variety

**Input**: `arr[]`, `variety`

**Structure**:
```
1. Include element at j
2. Shrink window from i (remove when frequency == 0)
3. Check if map.size() == k (variety)
```

---

### 9. Minimum Window Substring (Lecture 13)

**Problem**: Given two strings `s` and `t` of lengths `m` and `n` respectively, return the minimum window substring of `s` such that every character in `t` (including duplicates) is included in the window. If no such substring exists, return an empty string.

**Example**:
```
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"

Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
```

---

## Summary

The Sliding Window technique is powerful for:
- Optimizing brute force O(n²) solutions to O(n)
- Problems involving contiguous subarrays/substrings
- Both fixed and variable size window scenarios

**Key Strategy**: 
- Maintain a window that expands and/or contracts based on the problem constraints
- Use appropriate data structures (HashMap, Deque, etc.) to track window state efficiently
