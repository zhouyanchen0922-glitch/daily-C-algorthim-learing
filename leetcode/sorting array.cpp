//912.排序数组

//题目链接：https://leetcode.cn/problems/sort-an-array?q=%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84

//方法一：归并排序
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


//方法二：随机快排plus
class Solution {
public:
    int first,last;   //在类里面定义全局变量，方便后序递归的调用
    void partition(vector<int>& nums,int l,int r,int x){
        first = l,last = r;
        int i = l;
        while(i <= last){
            if(nums[i] == x){
                i++;
            }else if(nums[i] < x){
                swap(nums[first++],nums[i++]);
            }else {
                swap(nums[i],nums[last--]);
            }
        }
        
    }
    //以数组中随机生成的X数为标准，分成小于X，等与X，大于X
    void quick_sort(vector<int>& nums,int l,int r){
        if(l>=r) return;
        int x = nums[l + rand() % (r - l + 1)];    //数组中随机生成的X
        partition(nums,l,r,x);
        int left = first;
        int right = last;
        quick_sort(nums,l,left-1);
        quick_sort(nums,right+1,r);
    }

    vector<int> sortArray(vector<int>& nums) {
        srand(time(NULL));
        quick_sort(nums,0,(int)nums.size()-1);
        return nums;
    }
};
