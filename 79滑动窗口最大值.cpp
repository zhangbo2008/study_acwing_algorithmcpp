class Solution {
public:
    vector<int> maxInWindows(vector<int>& nums, int k) {
        vector<int>res;
        deque<int>q;
        for(int i = 0; i < nums.size(); i++){
            if(!q.empty() && i-q.front() >= k)//判断队头是否需要出队
                q.pop_front();
            while(!q.empty()&&nums[q.back()]<nums[i])//维护队列单调性
                q.pop_back();
            q.push_back(i);
            if(i >= k-1){
                res.push_back(nums[q.front()]);//取队头作为窗口最大元素
            }
        }
        return res;

    }
};