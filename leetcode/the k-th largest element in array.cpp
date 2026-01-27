#LCR 076.数组中的第K个最大元素

#题目链接https://leetcode.cn/problems/xx4gT2/

#方法一：运用快速排序时的分组情况确定第K个最大元素的位置
class Solution {
public:
    int first,last;

    void partition(vector<int>& nums,int l,int r,int x){
        first = l;
        last = r;
        int i = l;
        while(i<=last){
            if(nums[i] == x){
                i++;
            }else if(nums[i] < x){
                swap(nums[first++],nums[i++]);
            }else{
                swap(nums[i],nums[last--]);
            }
        }
    }
    //i为下标，partiton()将数组快排后，确定i在快排后数组中的位置
    //如果i正好在中间全部都是抽取的随机数x的区域（nums[first……last] = x），直接返回x；
    //若i小于first，在0……first-1进行partition();反之亦然
    int s(vector<int>& nums,int i){
        int ans = 0;
        for(int l = 0,r = nums.size() - 1;l<=r;){
            partition(nums,l,r,nums[l + rand() % (r - l + 1)]);
            if(i < first){
                r = first - 1;
            }else if(i > last){
                l = last + 1;
            }else{
                ans = nums[i];
                break;
            }
        }
        return ans;
    }


    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        return s(nums,nums.size() - k); //nums.size() - k确定数组排序后的第K个最大元素在数组中的下标
    }
};
