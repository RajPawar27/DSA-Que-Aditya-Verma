#include<bits/stdc++.h>
using namespace std;


//Maximum sum with subarray with window size k
//time complexity: O(n) & space complexity: O(1)
class lect3{
    public:
    int maxSumSubarrayK(vector<int> arr, int k){
        int n = arr.size();
        int maxSum = INT_MIN;
        int i=0, j=0;
        int windowSum = 0;

        while(j<n){
            windowSum += arr[j];

            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                maxSum = max(maxSum, windowSum);
                windowSum -= arr[i];
                i++;
                j++;
            }
        }
        
        return maxSum;
    }

};

//First Negative Number in every Window of Size K
// time complexity: O(n) & space complexity: O(k)
class lect4{
    public:
    vector<int> firstNegativeInWindowK(vector<int> arr, int k){
        int n = arr.size();

        vector<int> result; 
        if(k > n){
            return result;
        }

        queue<int> q;
        int i=0, j=0;

        while(j<n){

            if(arr[j] < 0){
                q.push(arr[j]);
            }

            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                if(q.empty()){
                    result.push_back(0);
                }
                else{
                    result.push_back(q.front());
                    if(arr[i] == q.front()){
                        q.pop();
                    }
                }
                i++;
                j++;
            }
        }

        return result;
    }
};

//count of occurance of anagrams 
//time complexity: O(n) & space complexity: O(1) array of fixed size 26    
class lect5{
    public:
    int countOfAnagrams(string txt, string pat){
        int n = txt.size();
        int m = pat.size();

        if(m > n){
            return 0;
        }

        vector<int> cntTxt(26, 0);
        vector<int> cntPat(26, 0);

        for(char ch : pat){
           cntPat[ch - 'a']++;
        }
        int i=0;
        int ans = 0;

        for(int j=0; j<n; j++){

            cntTxt[txt[j] - 'a']++;

            if(j-i+1 < m){
                continue;
            }
            else if(j-i+1 == m){
                if(cntTxt == cntPat){
                    ans++;
                }
                cntTxt[txt[i] - 'a']--;
                i++;
            }
        }

        return ans;
    }
};

//maximum of all subarray of size k
//time complexity: O(n) & space complexity: O(k)
class lect6{
    public:
    vector<int> maxOfAllSubarraysK(vector<int> arr, int k){

        int n = arr.size();
        vector<int> result;

        if(k > n){
            return result;
        }

        deque<int> dq; //stores indices

        int i=0, j=0;

        //process first k elements
        for(int i=0; i<k; i++){
            while(!dq.empty() && arr[dq.back()] < arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        //process rest of the elements
        for(int j=k; j<n; j++){

            //front of deque is the maximum of previous window
            result.push_back(arr[dq.front()]);

            //remove elements not part of current window
            while(!dq.empty() && dq.front() <= j-k){
                dq.pop_front();
            }

            //remove smaller elements as they are not useful
            while(!dq.empty() && arr[dq.back()] < arr[j]){
                dq.pop_back();
            }
            dq.push_back(j);
        }

        //maximum of last window
        result.push_back(arr[dq.front()]);

        return result;
    }
};

//max window with sum k 
class lect7{
    public:
    //better approach using hashmap to handle negative numbers
    //time complexity: O(n) & space complexity: O(n)
    int maxWindowWithSumKNegative(vector<int> arr, int k){
        int n = arr.size();
        unordered_map<int, int> prefixSumMap; //prefix sum to index
        int prefixSum = 0;
        int maxLength = 0;

        for(int i=0; i<n; i++){
            prefixSum += arr[i];

            if(prefixSum == k){
                maxLength = max(maxLength, i+1);
            }

            if(prefixSumMap.find(prefixSum) == prefixSumMap.end()){
                prefixSumMap[prefixSum] = i;
            }

            if(prefixSumMap.find(prefixSum - k) != prefixSumMap.end()){
                int length = i - prefixSumMap[prefixSum - k];
                maxLength = max(maxLength, length);
            }
        }

        return maxLength;
    }


    //max window with sum k : only non-negative numbers
    //time complexity: O(n) & space complexity: O(1)
    int maxWindowWithSumK(vector<int> arr, int k){
        int n = arr.size();
        int i=0, j=0;
        int windowSum = 0;
        int maxLength = 0;

        while(j<n){
            windowSum += arr[j];

            while(windowSum > k && i<=j){
                windowSum -= arr[i];
                i++;
            }

            if(windowSum == k){
                maxLength = max(maxLength, j-i+1);
            }

            j++;
        }

        return maxLength;
    }
};

//largest substring with k unique characters
class lect8{
    public:
    //brute force approach: O(n^2) & O(k)
    int largestSubstringKUniqueBrute(string s, int k){
        int n = s.size();
        int maxLength = 0;

        for(int i=0; i<n; i++){
            unordered_map<char, int> charCount;
            for(int j=i; j<n; j++){
                charCount[s[j]]++;
                if(charCount.size() == k){
                    maxLength = max(maxLength, j-i+1);
                }
                else if(charCount.size() > k){
                    break;
                }
            }
        }

        return maxLength;
    }

    //optimal approach: O(n) & O(k)
    int largestSubstringKUnique(string s, int k){
        int n = s.size();
        int i=0, j=0;
        unordered_map<char, int> charCount;
        int maxLength = 0;

        while(j<n){
            charCount[s[j]]++;

            while(charCount.size() > k){
                charCount[s[i]]--;
                if(charCount[s[i]] == 0){
                    charCount.erase(s[i]);
                }
                i++;
            }

            if(charCount.size() == k){
                maxLength = max(maxLength, j-i+1);
            }

            j++;
        }

        return maxLength;
    }
};

//largest substring with ALL unique characters
class lect9{
    public:
    //optimal approach: O(n) & O(k)
    int largestSubstringAllUnique(string s){
        int n = s.size();
        int i=0, j=0;
        unordered_map<char, int> mp;
        int maxLength = 0;

        while(j<n){
             mp[s[j]]++;

            while(mp.size() < (j - i + 1)){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }

            //all characters in current window are unique
            maxLength = max(maxLength, j - i + 1);
            j++;
        }

        return maxLength;
    }
};

//pick toys
class lect10{
    public:
    int pickToys(vector<int> arr, int varity){
        int n = arr.size();
        int i=0, j=0;
        unordered_map<int, int> toyCount;
        int maxToys = 0;

        while(j<n){
            toyCount[arr[j]]++;

            while(toyCount.size() > varity){
                toyCount[arr[i]]--;
                if(toyCount[arr[i]] == 0){
                    toyCount.erase(arr[i]);
                }
                i++;
            }
            if(toyCount.size() == varity)
                maxToys = max(maxToys, j - i + 1);
            
            j++;
        }

        return maxToys;
    }
};

//minum window substring
class lect11{
    public:
    string minWindowSubstring(string s, string t){
        int n = s.size();
        int m = t.size();

        if(m > n){
            return "";
        }

        unordered_map<char, int> targetMap;
        for(char ch : t){
            targetMap[ch]++;
        }

        unordered_map<char, int> windowMap;
        int i=0, j=0;
        int minLength = INT_MAX;
        int startIndex = -1;
        int formed = 0;
        int required = targetMap.size();

        while(j<n){
            char ch = s[j];
            windowMap[ch]++;

            if(targetMap.find(ch) != targetMap.end() && windowMap[ch] == targetMap[ch]){
                formed++;
            }

            while(i<=j && formed == required){
                ch = s[i];

                if(j - i + 1 < minLength){
                    minLength = j - i + 1;
                    startIndex = i;
                }

                windowMap[ch]--;
                if(targetMap.find(ch) != targetMap.end() && windowMap[ch] < targetMap[ch]){
                    formed--;
                }
                i++;
            }

            j++;
        }

        if(startIndex == -1){
            return "";
        }
        return s.substr(startIndex, minLength);
    }
};

int main(){
    //test for lect6 with negative numbers
    lect7 obj;
    vector<int> arr = {8,-2,10,5,2,7,1,-10};
    int k = 15;
    int result = obj.maxWindowWithSumKNegative(arr, k);
    cout << result << "\n";

    return 0;
}