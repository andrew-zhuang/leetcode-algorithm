// the same code for P46 and P47
class Solution {
    public List<List<Integer>> res = new ArrayList<List<Integer>>();
    public ArrayList<Integer> nums_now = new ArrayList<Integer>();

    public List<List<Integer>> permuteUnique(int[] nums) {
        for (int num : nums) {
            nums_now.add(num);
        }
        Collections.sort(nums_now);
        while (next_permutation()) {
            
        }
        return res;
    }

    public boolean next_permutation() {
//        System.out.println("nums: " + nums_now.toString());
//        System.out.println("res_before: " + res.toString());
        ArrayList<Integer> temp = new ArrayList<Integer>();
        for (int i = 0; i < nums_now.size(); i++) {
            temp.add(i, nums_now.get(i));
        }
        res.add(temp);
//        System.out.println(res.toString());
        int i = nums_now.size() - 1;

        for (; i > 0; i--) {
            if (nums_now.get(i) > nums_now.get(i-1))
                break;
        }
        if (i == 0)
            return false;
        int bound = i - 1;
//        System.out.println(bound);
        for (i = nums_now.size()-1; i >= bound; i--) {
            if (nums_now.get(i) > nums_now.get(bound)) {
                // swap
                int tmp = nums_now.get(bound);
                nums_now.set(bound, nums_now.get(i));
                nums_now.set(i, tmp);
                break;
            }
        }
        // sort

//        return false;
        quickSort(bound + 1, nums_now.size()-1);

        return true;
    }

    public void quickSort(int left, int right) {

//        return;
        if (left >= right)
            return;
//        System.out.println("left: " + left + "right: " + right);
        int p = partition(left, right);
        quickSort(left, p - 1);
        quickSort(p + 1, right);
    }

    public int partition(int left, int right) {
        int element = nums_now.get(right);
        int i = left;
        // 'element' represents the bound we need to partition
        // i points to element greater than 'element' which has the least index
        // j points to element less than 'element'
        for (int j = left; j < right; j++) {
            if (nums_now.get(j) < element) {
                int tmp = nums_now.get(i);
                nums_now.set(i, nums_now.get(j));
                nums_now.set(j, tmp);
                i++;
            }
        }
        int tmp = nums_now.get(i);
        nums_now.set(i, nums_now.get(right));
        nums_now.set(right, tmp);
        return i;
    }
}
