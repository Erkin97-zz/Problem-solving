class Solution {
public:
    int n;
    vector<vector<int>> roads;
    bool used[1000], exist[1000];
    void dfs1(int i, vector<vector<int>>& graph) {
        if (used[i]) return;
        used[i] = 1;
        if (i == n){
            exist[i] = 1;   
            return;
        }
        for (int j = 0; j < graph[i].size(); j++) {
            if (!used[graph[i][j]]) {
                dfs1(graph[i][j], graph);
            }
            exist[i] |= exist[graph[i][j]];
        }
    }
    void dfs2(int i, vector<vector<int>>& graph, vector<int> road) {
        road.push_back(i);
        if (i == n) {
            roads.push_back(road);
            return;   
        }
        for (int j = 0; j < graph[i].size(); j++) {
            if (exist[graph[i][j]] == 1) {
                dfs2(graph[i][j], graph, road);
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size() - 1;
        vector<int> start_road;
        dfs1(0, graph);
        if (exist[0]) dfs2(0, graph, start_road);
        return roads;
    }
};