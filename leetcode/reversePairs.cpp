#493，翻转对
#题目链接：https://leetcode.cn/problems/reverse-pairs?q=493

class Solution {
public:
    //find()函数的跨越比较是该小组的内部分组已经sort完了(该组整体此时还没有sort)
    int find(vector<int>&nums,int le,int ri){
        int res = 0,mid = le + (ri - le)/2;
        int i = le,j = mid+1;
        for(;i<=mid;i++){
            while(j <= ri && (long)nums[i] > 2*(long)nums[j]){
                res += mid - i + 1;
                j++;
            }
        }
        return res;
    }

    int merge_sort(vector<int>&nums,int temp[],int le,int ri){
        if(le>=ri) return 0;
        int mid = le + (ri - le)/2;

        int res = merge_sort(nums,temp,le,mid) +  //使用递归merge_sort,basic case 为只有一个数比较，返回res = 0.
                  merge_sort(nums,temp,mid+1,ri) +  //每一个大组分治成左右两个小组，当小组跳出下一层的merge_sort(不为basic case时),执行完find()以及下面这个排序过程后，才算完成当前这个组的merge_sort
                  find(nums,le,ri);    //每一个组的内部sort完成和当前该组find()完成，才算大组一次局部的merge_sort完成
                                        
      
        //进行sort(排序）的过程
        //小组内部左右两边分别设定起始下标比大小，用辅助数组接收值，在统一到原来的数组，完成sort
        int i = le,j = mid + 1,ind = le;
        while(i <= mid && j <= ri){
            if(nums[i]<=nums[j]) temp[ind++] = nums[i++];
            else temp[ind++] = nums[j++];
        }
        
        while(i<=mid) temp[ind++] = nums[i++];
        while(j<=ri) temp[ind++] = nums[j++];

        for(int ind = le;ind<=ri;ind++){
            nums[ind] = temp[ind];
        }
        return res;
    }


    int reversePairs(vector<int>& nums) {
        if(nums.empty()) return 0;
        int temp[nums.size()];
        memset(temp,0,sizeof(temp));
        return merge_sort(nums,temp,0,nums.size()-1);
    }
};
