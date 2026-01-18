//641.设计循环双端队列

//题目链接：https://leetcode.cn/problems/design-circular-deque?q=%E8%AE%BE%E8%AE%A1%E5%BE%AA%E7%8E%AF%E5%8F%8C%E7%AB%AF%E9%98%9F%E5%88%97

class MyCircularDeque {
    int* queue;
    int l, r, size, limit;

public:
    MyCircularDeque(int k) {
        queue = new int[k];
        l = r = size = 0;
        limit = k;
    }

    bool insertFront(int value) {
        if(isFull()){
            return false;
        }else{
            if(isEmpty()){
                l = r = 0;
                queue[0]=value;
                size++;
            }else{
                if(l-1<0)
                {
                    queue[limit-1] = value;
                    l = limit-1;
                    size++;
                }else{
                    queue[l-1] = value;
                    l--;
                    size++;
                }
            }
        }return true;
    }

    bool insertLast(int value) {
        if(isFull()){
            return false;
        }else{
            if(isEmpty()){
                l = r = 0;
                queue[0]=value;
                size++;
            }else{
                if(r+1>limit-1){
                    queue[0]=value;
                    r = 0;
                    size++;
                }else{
                    queue[r+1]=value;
                    r++;
                    size++;
                }
            }
        }return true;
    }

    bool deleteFront() {
        if(isEmpty()){
            return false;
        }else{
            l = (l==limit-1)?0:l+1;
            size--;
            return true;
        }
    }

    bool deleteLast() {
        if(isEmpty()){
            return false;
        }else{
            r =(r ==0)?limit-1:r-1;
            size--;
            return true;
        }
    }

    int getFront() {
        if(isEmpty()){
            return -1;
        }else{
            return queue[l];
        }
    }

    int getRear() {
        if(isEmpty()){
            return -1;
        }else{
            return queue[r];
        }
    }

    bool isEmpty() {
        if(size==0){
            return true;
        }else{
            return false;
        }
    }

    bool isFull() {
        if(size==limit){
            return true;
        }else{
            return false;
        }
    }
};
