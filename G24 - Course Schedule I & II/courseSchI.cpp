
// There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
// Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    queue<int> q;
	    int cnt = 0;
	    int indegree[N] = {0};
	    
	    vector<int> adj[N];
	    
	    for(auto it: prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    
	    for(int i = 0; i < N; i++){
	        for(auto it: adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    for(int i = 0; i < N; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    if(q.empty()){
	        return false;
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        cnt++;
	        
	        for(auto it: adj[node]){
	            if( --indegree[it] == 0) q.push(it);
	        }
	    }
	    
	    return cnt == N;
	    
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}