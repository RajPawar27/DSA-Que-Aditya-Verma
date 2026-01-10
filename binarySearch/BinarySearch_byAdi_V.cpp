#include<bits/stdc++.h>
using namespace std;

//basic Binary Search : array should be sorted
//Time Complexity: O(log n) & Space Complexity: O(1)
class lect02{
    public:
    int binarySearch(vector<int>& arr, int target){
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
};

//binary search for checking that order of the array is ascending or descending
//Time Complexity: O(log n) & Space Complexity: O(1)
class lect03{
    public:

    int bs(vector<int>&arr, int key)
    {
        order = isAscending(arr);
        int start = 0;  
        int end = arr.size() - 1;
        
        if(order) //ascending
        {
            while(start <= end)
            {
                int mid = start + (end - start) / 2;
                
                if(arr[mid] == key)
                    return mid;
                else if(arr[mid] < key)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        else //descending
        {
            while(start <= end)
            {
                int mid = start + (end - start) / 2;
                
                if(arr[mid] == key)
                    return mid;
                else if(arr[mid] > key)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }

    bool isAscending(vector<int>& arr){
        return arr[0] < arr[arr.size() - 1];
    }
};


//finding the first and last occurrence of an element in a sorted array
//Time Complexity: O(log n) & Space Complexity: O(1)
class lect04{   
    public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int first = -1, last = -1 ;

        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(arr[mid] == target){
                first = mid;
                high = mid - 1 ;
            }
            else if(arr[mid] > target){
                high = mid-1;
            }
            else{
                low = mid +1;
            }
        }
        low = 0;
        high = n-1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(arr[mid] == target){
                last = mid;
                low = mid + 1;
            }
            else if(arr[mid] > target){
                high = mid-1;
            }
            else{
                low = mid +1;
            }
        }

        return {first,last};
    }
}


//couting occurrences of an element in a sorted array
//Time Complexity: O(log n) & Space Complexity: O(1)
class lect05{
    public:
    int countOccurrences(vector<int>& arr, int target) {
        int n = arr.size();
        
        int first = findFirstOccurrence(arr, target);
        if (first == -1) {
            return 0; // Target not found
        }
        
        int last = findLastOccurrence(arr, target);
        
        return last - first + 1;
    }

    int findFirstOccurrence(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;
        int first = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                first = mid;
                high = mid - 1; // Continue searching in the left half
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return first;
    }

    int findLastOccurrence(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;
        int last = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                last = mid;
                low = mid + 1; // Continue searching in the right half
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return last;
    }
};


//find minimum in rotated sorted array (no of thimes sorted array is rotated)
class lect06{
    public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            int prev = (n + mid - 1) % n;
            int next = (mid + 1) % n;

            if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) {
                return arr[mid];
            }
            else if (arr[mid] <= arr[high]) {
                high = mid - 1;
            } 
            else if (arr[mid] >= arr[low]) {
                low = mid + 1;
            }
        }
        return -1; // This line should never be reached if the input array is a rotated sorted array
    }
}; 

//search in rotated sorted array (with help og class lect06)
class lect07{
    public:
    int searchInRotatedSortedArray(vector<int>& arr, int target) {
        lect06 finder;
        int minElement = finder.findMin(arr);
        int n = arr.size();
        int pivotIndex = -1;

        // Find the index of the minimum element (pivot)
        for (int i = 0; i < n; i++) {
            if (arr[i] == minElement) {
                pivotIndex = i;
                break;
            }
        }

        int result = binarySearch(arr, 0, pivotIndex - 1, target);
        if (result != -1) {
            return result;
        }
        return binarySearch(arr, pivotIndex, n - 1, target);
    }

    int binarySearch(vector<int>& arr, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                return mid;
            } 
            else if (arr[mid] < target) {
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
};


//finding floor element in a sorted array
class lect08{
    public:
    int findFloor(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;
        int floorIndex = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                return arr[mid];
            } 
            else if (arr[mid] < target) {
                floorIndex = mid; // Update floor index
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }

        return (floorIndex != -1) ? arr[floorIndex] : -1; // Return -1 if no floor exists
    }
};

//finding ceiling element in a sorted array
class lect09{
    public:
    int findCeiling(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;
        int ceilingIndex = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                return arr[mid];
            } 
            else if (arr[mid] < target) {
                low = mid + 1;
            } 
            else {
                ceilingIndex = mid; // Update ceiling index
                high = mid - 1;
            }
        }

        return (ceilingIndex != -1) ? arr[ceilingIndex] : -1; // Return -1 if no ceiling exists
    }
};

// finding next alphabet in a sorted array of characters
class lect10{
    public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size() - 1;
        char result = letters[0]; // Default to the first letter (wrap around)

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if(letters[mid] == target) {
                low = mid + 1; // Move right to find the next greater letter
            } 
            else if (letters[mid] > target) {
                result = letters[mid]; // Update result
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }

        return result;
    }
};

// finding ele in infintely sorted Array
class lect11{
    public:
    int searchInInfiniteArray(vector<int>& arr, int target) {
        // First, find the range where the target might be present
        int low = 0;
        int high = 1;

        // Expand the range exponentially until the target is within the range
        while (arr[high] < target) {
            low = high;
            high = high * 2; // Double the high index
            if (high >= arr.size()) { // Prevent going out of bounds
                high = arr.size() - 1;
                break;
            }
        }

        // Now perform binary search within the found range
        return binarySearch(arr, low, high, target);
    }

    int binarySearch(vector<int>& arr, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                return mid;
            } 
            else if (arr[mid] < target) {
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
};

//  find First occurace of 1 in binary array 
class lect12{
    public:
    int firstOccurrenceOfOne(vector<int>& arr) {
        int low = 0;
        int high = 0;

        while(!arr[high]){
            low = high;
            high = 2 * high + 1; // Exponentially increase high index
            if (high >= arr.size()) { // Prevent going out of bounds
                high = arr.size() - 1;
                break;
            }
        }

        return bs(arr, low, high);
    }
    int bs(vector<int>& arr, int low, int high) {
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == 1) {
                result = mid; // Update result and search in the left half
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }
        return result;  
    }
};

//minimum difference element in sorted array
//Time Complexity: O(log n) & Space Complexity: O(1)
// incase if assking min diff  : abs(arr[i] - target)
class lect13{
    public:
    int findMinDifferenceElement(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;

        // Handle edge cases
        if (target <= arr[low]) {
            return arr[low];
        }
        if (target >= arr[high]) {
            return arr[high];
        }

        
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                return arr[mid];
            } 
            else if (arr[mid] < target) {
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }

        // After the loop, low is the index of the smallest element greater than target
        // and high is the index of the largest element smaller than target
        if ((arr[low] - target) < (target - arr[high])) {
            return arr[low];
        } 
        else {
            return arr[high];
        }
    }
};

// peak element 
class lect14{
    public:
    int findPeakElement(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        int n = arr.size ();
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (mid > 0  && mid < n-1) {
                if(arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1]) {
                    return mid;
                } 
                else if (arr[mid - 1] > arr[mid]) {
                    high = mid - 1;
                } 
                else {
                    low = mid + 1;
                }
            }
            else if (mid == 0) {
                if (arr[0] >= arr[1]) {
                    return 0;
                } 
                else {
                    return 1;
                }
            } 
            else if (mid == n - 1) {
                if (arr[n - 1] >= arr[n - 2]) {
                    return n - 1;
                } 
                else {
                    return n - 2;
                }
            }
        }
    }
};

// searching ele in bitonic array 
class lect15{
    public:
    int searchInBitonicArray(vector<int>& arr, int target) {
        int peakIndex = findPeakIndex(arr);
        
        int result = binarySearch(arr, 0, peakIndex, target, true);
        if (result != -1) {
            return result;
        }
        return binarySearch(arr, peakIndex + 1, arr.size() - 1, target, false);
    }

    int findPeakIndex(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] > arr[mid + 1]) {
                high = mid;
            } 
            else {
                low = mid + 1;
            }
        }
        return low; // Peak index
    }

    int binarySearch(vector<int>& arr, int low, int high, int target, bool isAscending) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                return mid;
            } 
            else if (isAscending ? (arr[mid] < target) : (arr[mid] > target)) {
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
};  

//Search in a row wise column wise sorted array
class lect16{
    public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        
        

        return false;
    }
};
int main(){
    
    return 0;
}