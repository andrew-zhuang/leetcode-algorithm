// 22.18%, 5.06%
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3)
            return result;
        sort(nums.begin(), nums.end());
        int same = 0, zero_num = 0;
        for(auto i = nums.begin()+1; i != nums.end(); i++){
            if(*i == *(i-1)){
                if(same == 2){
                    nums.erase(i);
                    i--;
                }
                else
                    same++;
            }
            else
                same = 0;
        }
        //for(auto i = nums.begin(); i != nums.end(); i++)
            //cout<<*i<<" ";
        //cout<<nums.size()<<endl;;
        for(auto i = nums.begin(); i != nums.end(); i++){
            if(*i != 0) continue;
            //cout<<zero_num<<endl;
            while(*i == 0){
                //cout<<*i<<" ";
                zero_num++;
                i++;
                if(i == nums.end()) break;
            }
            cout<<zero_num<<endl;
            if(zero_num == 3){
                result.push_back({0, 0, 0});
            }
            while(zero_num != 1){
                //cout<<*i<<endl;
                i--;
                nums.erase(i);
                zero_num--;
            }
            break;
        }
        //for(auto i = nums.begin(); i != nums.end(); i++)
            //cout<<*i<<" ";
        if(nums.size() < 3)
            return result;

        int left = 0, right = 0, temp_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            //cout<<i<<endl;
            if(i >= 2 && nums[i] == nums[i-1] && nums[i] == nums[i-2]){
                continue;
            }
            if(i <= (nums.size()-3) && nums[i] == nums[i+1] && nums[i] == nums[i+2]){
                continue;
            }
            left = 0, right = nums.size()-1, temp_sum = 0;
            if(i <= (nums.size()-2) && i >= 1 && nums[i] == nums[i+1] && nums[i] != nums[i-1])
                right = i+1;
            while(left < i && right > i){
                temp_sum = nums[i] + nums[left] + nums[right];
                int old_left = nums[left], old_right = nums[right];
                if(temp_sum == 0){
                    vector<int> ans = {nums[left], nums[i], nums[right]};
                    result.push_back(ans);
                    while(nums[left] == old_left && left <= i)
                        left++;
                    while(nums[right] == old_right && right >= i)
                        right--;
                }
                else if(temp_sum > 0)
                    while(nums[right] == old_right && right >= i)
                        right--;
                else
                    while(nums[left] == old_left && left <= i)
                        left++;
            }
        }
        return result;
    }
};
