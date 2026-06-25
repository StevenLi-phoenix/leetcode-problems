// @leetcode id=380 questionId=380 slug=insert-delete-getrandom-o1 lang=cpp site=leetcode.com title="Insert Delete GetRandom O(1)"
class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> valToIndex;
    
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        // If val already exists, return false
        if (valToIndex.find(val) != valToIndex.end()) {
            return false;
        }
        // Add val to the end of nums
        nums.push_back(val);
        // Store the mapping: val -> index in nums
        valToIndex[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        // If val doesn't exist, return false
        if (valToIndex.find(val) == valToIndex.end()) {
            return false;
        }
        
        // Get the index of val to remove
        int indexToRemove = valToIndex[val];
        
        // Get the last element
        int lastElement = nums.back();
        
        // Move last element to the position of element to remove
        nums[indexToRemove] = lastElement;
        
        // Update the index of last element
        valToIndex[lastElement] = indexToRemove;
        
        // Remove the last element
        nums.pop_back();
        
        // Remove val from the map
        valToIndex.erase(val);
        
        return true;
    }
    
    int getRandom() {
        // Get a random index between 0 and nums.size()-1
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
