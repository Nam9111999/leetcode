#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {

public:
    void kahn(vector<int>& degree, vector<vector<int>>& v) {
        queue<int> q;
        for(int i =0;i<degree.size();i++){
            if(degree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int head = q.front();q.pop();
            for(auto x:v[head]) {
                degree[x]--;
                if (degree[x] == 0){
                    q.push(x);
                }
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses == 1) return true;
        vector<vector<int>>v(numCourses);
        vector<int> degree(numCourses);
        for(auto x: prerequisites){
            v[x[1]].push_back(x[0]);
            degree[x[0]]++;
        }

        kahn(degree,v);
        for (auto x:degree) {
            if (x!= 0) return false;
        }

        return true;
        
    }
};

int main(){
    std::vector<std::vector<int>> prerequisites(1);
    prerequisites[0].push_back(1);
    prerequisites[0].push_back(0);
    Solution su;
    su.canFinish(2,prerequisites);
}