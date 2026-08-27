class MyHashSet {
public:

vector<bool> nums;
MyHashSet() : nums(1000001, false) {}

    void add(int key) {
        nums[key] = true;
    }
    
    void remove(int key) {
        nums[key] = false;
    }
    
    bool contains(int key) {
        return nums[key];
    }
};