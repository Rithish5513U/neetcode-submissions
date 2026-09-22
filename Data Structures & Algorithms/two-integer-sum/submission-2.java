class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        Map<Integer, Integer> numIndex = new HashMap<>();
        for(int i=0; i<n; i++){
            int rem = target - nums[i];
            if(numIndex.get(rem) != null){
                int[] result = new int[2];
                result[0] = numIndex.get(rem);
                result[1] = i;
                return result;
            }
            numIndex.put(nums[i], i);
        }
        return new int[2];
    }
}
