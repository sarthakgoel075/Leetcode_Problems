class MedianFinder {
public:
     priority_queue<int>leftmax;
    priority_queue<int,vector<int>,greater<int>>rightmin;
    MedianFinder() {
  
    }
    
    void addNum(int num) {
        if(leftmax.size()==0 || num < leftmax.top()){
            leftmax.push(num);
        }
        else{
            rightmin.push(num);
        }
        if(abs((int)leftmax.size()-(int)rightmin.size())>1){
            rightmin.push(leftmax.top());
            leftmax.pop();
        }
        else if(rightmin.size()>leftmax.size()){
            leftmax.push(rightmin.top());
            rightmin.pop();
        }
    }
    
    double findMedian() {
        if(leftmax.size()==rightmin.size()){
            double median=double(leftmax.top()+rightmin.top())/2;
            return median;
        }
        else{
            return leftmax.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */