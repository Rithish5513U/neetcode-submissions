class Solution {
    public boolean hasDuplicate(int[] nums) {
        int n = nums.length;
        HashSet<Integer> seenNumbers = new HashSet<Integer>();

        for(int i = 0; i < n; i++){
            if(seenNumbers.contains(nums[i])){
                return true;
            }
            seenNumbers.add(nums[i]);
        }

        return false;
    }
}