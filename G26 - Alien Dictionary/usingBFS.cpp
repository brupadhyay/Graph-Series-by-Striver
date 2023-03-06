/*Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.*/

#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        
        string ans = "";
        
        vector<int> adj[K];
        
        //O(N * len)
        for(int i = 0; i < N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int len = min(s1.size(), s2.size());
            
            
            bool flag = false;
            
            for(int j = 0; j < len; j++){
                if(s1[j] != s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    flag = true;
                    break;
                }
            }
            //edge case 1 ->
            //if all the character matches and bigger string
            //appears before shorter
            
            if(flag == false && s1.size() > s2.size()){
                return "";
            }
        }
        
        int indegree[K] = {0};
        //O(K)
        for(int i = 0; i < K; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        //O(K)
        for(int i = 0;i<K;i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        if(q.empty()) return "";
        
        //O(K + E) in DG - total degree = E
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans += (node + 'a');
            
            for(auto it: adj[node]){
                if(--indegree[it] == 0) q.push(it);
            }
        }
        
        //edge case 2 - if cyclic dependency then topo Sort fails
        if(ans.size() < K) return "";
        
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        if(order == ""){
            cout << 0 << endl;
            return 0;
        } 

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
