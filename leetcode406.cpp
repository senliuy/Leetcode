class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        //大神分析过程
        //先按pair的第一个元素排序从大大小，如果相等，则按第二个元素从小到大排序
        //遍历排序好的数组
        //在新的vector里面插入起始位置到第二个元素的位置
        //例子
        //第一次排序：[7,0],[7,1],[6,1],[5,0],[5,2],[4,4]
        //[7,0] 插入到位置0, res: [7,0]
        //[7,1] 插入到位置1, res: [7,0],[7,1]
        //[6,1] 插入到位置1, res: [7,0],[6,1],[7,1]
        //[5,0] 插入到位置0, res: [5,0],[7,0],[6,1],[7,1]
        //[5,2] 插入到位置2, res: [5,0],[7,0],[5,2],[6,1],[7,1]
        //[4,4] 插入到位置4, res: [5,0],[7,0],[5,2],[6,1],[4,4],[7,1]
        sort(people.begin(), people.end(), [](const pair<int, int>&a, const pair<int, int>&b){
            return a.first>b.first || (a.first==b.first && a.second < b.second);
        });
        vector<pair<int, int>> res;
        for(auto a:people){
            res.insert(res.begin()+a.second, a);
        }
        return res;
    }
};