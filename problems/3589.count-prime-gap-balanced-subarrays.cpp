// @leetcode id=3589 questionId=3907 slug=count-prime-gap-balanced-subarrays lang=cpp site=leetcode.com title="Count Prime-Gap Balanced Subarrays"
class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        const int MAXV = 50001;
        vector<bool> isComposite(MAXV + 1, false);
        isComposite[0] = isComposite[1] = true;
        for (int i = 2; (long long)i * i <= MAXV; i++) {
            if (!isComposite[i]) {
                for (int j = i * i; j <= MAXV; j += i) isComposite[j] = true;
            }
        }

        deque<int> maxDeque, minDeque;
        vector<int> primePositions;
        long long total = 0;
        int left = 0;

        for (int r = 0; r < n; r++) {
            bool isPrime = nums[r] <= MAXV && !isComposite[nums[r]];
            if (isPrime) {
                while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[r]) maxDeque.pop_back();
                maxDeque.push_back(r);
                while (!minDeque.empty() && nums[minDeque.back()] >= nums[r]) minDeque.pop_back();
                minDeque.push_back(r);
                primePositions.push_back(r);
            }

            while (!maxDeque.empty() && !minDeque.empty() &&
                   nums[maxDeque.front()] - nums[minDeque.front()] > k) {
                left++;
                if (maxDeque.front() < left) maxDeque.pop_front();
                if (minDeque.front() < left) minDeque.pop_front();
            }

            int count = primePositions.size();
            if (count >= 2) {
                int Lcm = primePositions[count - 2];
                int Ldm = left;
                if (Lcm >= Ldm) total += (Lcm - Ldm + 1);
            }
        }
        return (int)total;
    }
};
