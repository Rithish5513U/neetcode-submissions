class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        int z = 0;
        int product = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                z++;
            }
            else{
                product *= nums[i];
            }
        }
        if(z > 1){
            return result;
        }
        else if(z == 1){
            for(int i = 0; i < n; i++){
                if(nums[i] == 0){
                    result[i] = product;
                    return result;
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                result[i] = product / nums[i];
            }
        }
        return result;
    }
}  
