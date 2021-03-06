/*
现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。

可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。

示例 1:

输入: 2, [[1,0]] 
输出: [0,1]
解释: 总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。
示例 2:

输入: 4, [[1,0],[2,0],[3,1],[3,2]]
输出: [0,1,2,3] or [0,2,1,3]
解释: 总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
     因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。
说明:

输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
你可以假定输入的先决条件中没有重复的边。
提示:

这个问题相当于查找一个循环是否存在于有向图中。如果存在循环，则不存在拓扑排序，因此不可能选取所有课程进行学习。
通过 DFS 进行拓扑排序 - 一个关于Coursera的精彩视频教程（21分钟），介绍拓扑排序的基本概念。
拓扑排序也可以通过 BFS 完成。

*/
//解答：类似题207，用拓扑序列做
#include <vector>
#include <set>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        if(prerequisites.size() == 0)
        {
            for(int i = 0; i < numCourses; i++)
            {
                result.push_back(i);
            }
            
            return result;
        }
        
        vector<int> inDegree(numCourses, 0);
        vector<set<int>> successors(numCourses, set<int>());
        for(int i = 0; i < prerequisites.size(); i++)
        {
            inDegree[prerequisites[i][0]]++;
            successors[prerequisites[i][1]].insert(prerequisites[i][0]);
        }
        
        queue<int> q;
        for(int i = 0; i < inDegree.size(); i++)
        {
            if(inDegree[i] == 0)
                q.push(i);
        }
        
        int count = 0;
        int index;
        while(!q.empty())
        {
            index = q.front();
            result.push_back(index);
            q.pop();
            count++;
            for(auto it = successors[index].begin(); it !=  successors[index].end(); it++)
            {
                inDegree[*it]--;
                if(inDegree[*it] == 0)
                {
                    q.push(*it);
                }
            }
        }
        if(count == numCourses)
            return result;
        else
            return vector<int>();
        
    }
};