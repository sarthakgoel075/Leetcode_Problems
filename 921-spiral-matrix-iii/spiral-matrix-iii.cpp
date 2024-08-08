class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int total=rows*cols;
        int currsize=0;
        vector<vector<int>>ans;
        int hor=1;
        int flag=1;
          if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols){
                ans.push_back({rStart,cStart});
                currsize++;
            }
        while(currsize<total){
          
            for(int i=0;i<hor;i++){
                cStart+=flag;
                if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols){
                ans.push_back({rStart,cStart});
                currsize++;
            }}
                for(int i=0;i<hor;i++){
                rStart+=flag;
                if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols){
                ans.push_back({rStart,cStart});
                currsize++;
            }
            }
            flag=flag*(-1);
            hor++;
        }
        return ans;
    }
};