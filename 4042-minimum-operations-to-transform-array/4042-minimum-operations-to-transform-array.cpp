class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();               
        long long baseSum = 0;               
        for (int i = 0; i < n; ++i) {
            baseSum += llabs((long long)nums1[i] - (long long)nums2[i]);
        }

        long long best = LLONG_MAX;
        int last = nums2[n]; 

        for (int p = 0; p < n; ++p) {
            long long cost_except_p = baseSum - llabs((long long)nums1[p] - (long long)nums2[p]);

            // Now compute minimal cost to produce both nums2[p] and nums2[n]
            // from starting value a = nums1[p]:
            long long a = nums1[p];
            long long t1 = nums2[p];
            long long t2 = last;

            // median of (a, t1, t2)
            long long med;
            // simple way: put into array and sort 3 elements
            long long arr[3] = {a, t1, t2};
            sort(arr, arr + 3);
            med = arr[1];

            long long cost_p = llabs(a - med) + llabs(t1 - med) + llabs(t2 - med);

            long long total = cost_except_p + cost_p;
            if (total < best) best = total;
        }

        // +1 for the append operation itself
        return best + 1;
    }
};
