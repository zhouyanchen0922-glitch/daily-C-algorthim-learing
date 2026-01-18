//155.最小栈

//题目链接：https://leetcode.cn/problems/min-stack?q=%E6%9C%80%E5%B0%8F%E6%A0%88

class MinStack {
    stack<int>data;
    stack<int>minarr;
public:
    MinStack() {
        
    }
    
    void push(int val) {
       data.push(val);
       if(minarr.empty()||val<minarr.top()){
        minarr.push(val);
       }else{
        minarr.push(minarr.top());
       }
    }
    
    void pop() {
        if(!data.empty()){
            data.pop();
            minarr.pop();
        }
    }
    
    int top() {
        return data.empty()?INT_MIN:data.top();
    }
    
    int getMin() {
        return minarr.empty() ? INT_MIN : minarr.top();
    }
};
