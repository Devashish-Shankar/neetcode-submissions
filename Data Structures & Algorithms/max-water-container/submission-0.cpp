class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = 0;
        int left = 0;
        int right = heights.size()-1;
        while(left < right){
            int width = right-left;
            int currHeight = min(heights[left], heights[right]);
            int currArea = width * currHeight;
            area = max(currArea, area);
            if(heights[left]<heights[right]){
                left++;
            }else{
                right--;
            }
        }
        return area;
    }
};
