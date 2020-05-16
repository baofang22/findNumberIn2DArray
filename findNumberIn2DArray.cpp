/*
《剑指Offer》面试题04：二维数组中的查找
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，
判断数组中是否含有该整数。

 

示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


//解法一：右上角比较法
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        bool found=false;
        if(matrix.size()>0){
            int row=0;
            int column=matrix[0].size()-1;
            int rows = matrix.size();
            int columns = matrix[0].size();
            while(row<rows && column>=0){
                if(matrix[row][column]==target){
                 found=true;
                  break;//找到后一定要终止循环，不然会超出时间限制
                }else{
                    //如果右上角的数字大于所找数字，则删除(排除)其所在列
                    if(matrix[row][column]>target){
                        --column;
                    }else{
                    //如果右上角的数字小于所找数字，则删除(排除)其所在行
                        ++row;
                    }
                }
            }
        }
        return found;
    }
};

