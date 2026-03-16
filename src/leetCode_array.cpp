#include <vector>
#include <unordered_map>
using namespace std;


// O(n^2)
vector<int> twoSum(vector<int> &nums, int target){
    int n = nums.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(nums[i] + nums[j] == target){
                return {i,j};
            }
        }
    }return {};
}


// or best complexity with HashMap O(n)

vector<int> twoSumHashMap(vector<int>& nums, int target){
    unordered_map<int, int> seen;
    int n = nums.size();

    for(int i = 0; i < n; i++){
        int needed = target - nums[i];

        if(seen.count(needed)){
            return {seen[needed], i};
        }
        seen[nums[i]] = i;
    }
    return {};
}



