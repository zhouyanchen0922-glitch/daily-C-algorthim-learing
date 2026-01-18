//912.排序数组

//题目链接：https://leetcode.cn/problems/sort-an-array?q=%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84

class Solution {
    vector<int> tmp;
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int mid = l + (r - l)/2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        int i = l;
        int j = mid + 1;
        int count = 0;
        while (i <= mid && j <= r) {
            if (nums[i] >= nums[j]) {
                tmp[count++] = nums[j++];
            } else {
                tmp[count++] = nums[i++];
            }
        }
        while(i <= mid) {
            tmp[count++] = nums[i++];
        }
        while(j <= r) {
            tmp[count++] = nums[j++];
        }
        
        for (int i = 0; i < r - l + 1; i++) {
            nums[i+l] = tmp[i];
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        tmp.resize((int)nums.size(), 0);//把容器 tmp 的元素个数调整为和 nums 的元素个数一样多，并且所有元素（尤其是新增的元素）都初始化为 0。
        mergeSort(nums,0,(int)nums.size()-1);
        return nums;

    }
};
