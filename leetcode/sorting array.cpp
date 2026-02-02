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

//方法三：基数排序
class Solution {
public:
    const int base = 16; // 十六进制基数，正常工作

    // 求数字的位数（针对base=16）
    int bit(int max_val) {
        int ans = 0;
        while (max_val) {
            max_val /= base;
            ans++;
        }
        //max_val=0时返回1，确保排序逻辑执行（严谨性优化）
        return ans == 0 ? 1 : ans;
    }

    void radixsort(vector<int>& nums, int bits) {
        int n = nums.size();
        vector<int> temp(n); // 动态临时数组，无固定大小限制，更安全
        
        for (int offset = 1; bits > 0; offset *= base, bits--) {
            vector<int> arr(base, 0); // 十六进制桶（0~15），初始化为0
            
            // 步骤1：统计每个桶的元素个数
            for (int i = 0; i < n; i++) {
                arr[(nums[i] / offset) % base]++;
            }
            
            // 修复1：前缀和循环从i=1开始，避免arr[-1]数组越界（核心修复）
            for (int i = 1; i < base; i++) {
                arr[i] = arr[i] + arr[i - 1];
            }
            
            // 步骤2：逆序遍历，保证基数排序的稳定性
            for (int i = n - 1; i >= 0; i--) {
                temp[--arr[(nums[i] / offset) % base]] = nums[i];
            }
            
            // 步骤3：复制回原数组
            for (int i = 0; i < n; i++) {
                nums[i] = temp[i];
            }
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() > 1) {
            int n = nums.size();
            int min_val = nums[0];
            
            // 查找数组最小值
            for (int i = 0; i < n; i++) {
                min_val = min(min_val, nums[i]);
            }
            
            int max_val = 0;
            // 偏移数组元素为非负数（基数排序核心前提），并查找最大值
            for (int i = 0; i < n; i++) {
                nums[i] -= min_val;
                max_val = max(max_val, nums[i]);
            }
            
            // 调用基数排序（传入最大元素的位数）
            radixsort(nums, bit(max_val));
            
            // 还原数组元素（偏移量回补）
            for (int i = 0; i < n; i++) {
                nums[i] += min_val;
            }
        }
        
        return nums;
    }
};
