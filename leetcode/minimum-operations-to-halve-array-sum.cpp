#2208 将数组和减半的最少的操作次数

#题目链接：https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/description/

//整个思路为：利用大顶堆的性质，每次取容器中最大的数减小一般，使总减小的和>=原来元素总和一半的操作次数最小
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq(nums.begin(),nums.end());  //新建一个大顶堆
                                                             //(nums.begin(),nums.end())是直接将容器的第一个元素和最后一个元素输入进堆并排序
        int ans = 0;
        double sum = accumulate(nums.begin(),nums.end(),0.0),sum2 = 0.0;   //accumulate(nums.begin(),nums.end(),0.0)  加和函数，最后的“0.0”是和的数据类型——浮点数
        while(sum2 < sum/2){
            double x = pq.top();
            pq.pop();
            sum2 += x / 2;
            pq.push(x / 2);
            ans++;
        }
        return ans;
    }
};
