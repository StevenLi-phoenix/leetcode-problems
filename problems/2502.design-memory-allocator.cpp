// @leetcode id=2502 questionId=2587 slug=design-memory-allocator lang=cpp site=leetcode.com title="Design Memory Allocator"
class Allocator {
public:
    Allocator(int n) : mem(n, 0) {
    }

    int allocate(int size, int mID) {
        int n = mem.size();
        int i = 0;
        while (i < n) {
            if (mem[i] != 0) { i++; continue; }
            int j = i;
            while (j < n && mem[j] == 0 && j - i < size) j++;
            if (j - i == size) {
                for (int k = i; k < j; k++) mem[k] = mID;
                return i;
            }
            i = j + 1;
        }
        return -1;
    }

    int freeMemory(int mID) {
        int count = 0;
        for (int i = 0; i < (int)mem.size(); i++) {
            if (mem[i] == mID) {
                mem[i] = 0;
                count++;
            }
        }
        return count;
    }

private:
    vector<int> mem;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
