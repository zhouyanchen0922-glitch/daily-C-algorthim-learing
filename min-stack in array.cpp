#leetcode 155.最小栈 
#题目链接 https://leetcode.cn/problems/min-stack/
class MinStack {

static const int max = 8001;
int data[max];
int minarr[max];
int size;

public:
    MinStack() {
        size = 0;
    }
    
    void push(int val) {
        if(size<max)
        {
            data[size]=val;
            if(size==0||val<minarr[size-1])
            {
                minarr[size]=val;
            }else
            {
                minarr[size]=minarr[size-1];
            }
            size++;
        }
    }
    
    void pop() {
        if(size>0)
        {
            size--;
        }

    }
    
    int top() {
        return size > 0 ? data[size - 1] : INT_MIN;
    }
    
    int getMin() {
        return size > 0 ? minarr[size - 1] : INT_MIN;
    }
};
