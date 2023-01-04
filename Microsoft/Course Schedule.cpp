class Solution {
public:
    
    bool detectCycle(vector<int>adj[],int src, vector<bool>&visited,vector<bool>&recVis){
        if(!visited[src]){
        visited[src] = true;
            recVis[src]=true;

        vector<int>::iterator itr;

        for(itr = adj[src].begin(); itr!= adj[src].end(); itr++){

            if(!visited[*itr] && detectCycle(adj,*itr,visited,recVis))return true;

            
            else if(recVis[*itr]==true){
                return true;
            }

        }
    }
    recVis[src]=false;
    return false;
    }
    
        
   

    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(auto itr:prerequisites){
            adj[itr[0]].push_back(itr[1]);
        
        }
        vector<bool>visited(numCourses,false);
        vector<bool>recVis(numCourses,false);
        for(int i=0;i<numCourses;i++){
                if(detectCycle(adj,i,visited,recVis)==true)return false;  
        }   
        
        return true;
            
    }
    
};
