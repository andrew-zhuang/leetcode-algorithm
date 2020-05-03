int* twoSum(int* nums, int numsSize, int target, int* returnSize){
        int i,j;
        static int returnarry[2] = {-1};
        for(i=0;i<numsSize - 1;i++){
            for(j=i+1;j<numsSize;j++){
                if(nums[i] + nums[j] == target) {
                    returnarry[0] = i;
                    returnarry[1] = j;
                    * returnSize = 2;
                    return returnarry;
                }
            }
        }            
        return 0;
}
