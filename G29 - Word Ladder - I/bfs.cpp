/*Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList
The second part of this problem can be found here.

Note: If no possible way to transform sequence from startWord to targetWord return 0

*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
       
       queue<pair<string , int>>q;  
       q.push({startWord , 1});
       
       //set for checking words effectively - O(N) space
       unordered_set<string>st(wordList.begin() , wordList.end());
       st.erase(startWord);
       
       while(!q.empty()){
           
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            // we return the steps as soon as
            // the first occurence of targetWord is found.
            if(word == targetWord) return steps;
            

            // N * wordLength * 26
            for(int i=0 ; i<word.size() ; i++){
                // Now, replace each character of ‘word’ with char
                // from a-z then check if ‘word’ exists in wordList.
                char original = word[i];
                
                for(char ch = 'a' ; ch<='z' ; ch++){
                    word[i] = ch; 
                    // check if it exists in the set and push it in the queue.
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word , steps + 1});
                    }
                }
                
                word[i] = original;
                
            }
       }
       // If there is no transformation sequence possible
       return 0;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}