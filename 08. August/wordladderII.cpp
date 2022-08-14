class Solution {
public:
	
	
	bool canBeNext(string s1, string s2){
		int uncmn=0;
		for(int i=0; i<s1.size(); i++)
			uncmn += (s1[i] != s2[i]);

		return uncmn==1;
	}
	
	
	void bfs(vector<vector<int>>& graph, vector<int> parent[], int n, int start, int end){
		vector<int> dist(n, 501); 
		queue<int> q; 
		q.push(start);

		dist[start] = 0; 
		parent[start] = {-1}; 

		while(!q.empty()){
			
			int curr = q.front();
			q.pop();
			
			// Traversing all the connected elements of curr (Here nearest(convertable) words indexes)
			for( int node: graph[curr]){
				if(dist[node] > dist[curr]+1){ // if marked distance is more than possible distance i.e, found nearest node (here word) 
					dist[node] = dist[curr]+1;
					q.push(node);
					parent[node].clear(); // Removing previously calculated distant than current word
					parent[node].push_back(curr); // adding current word index
				}else if(dist[node] == dist[curr]+1) // if node(next word) is just one move ahead the current 
					parent[node].push_back(curr);
			}
		}

	}
	
	// All the paths in the form of indexes of words from wordList
	void shortestPaths(int node, vector<vector<int>>& Paths, vector<int>& curr_path, vector<int> parent[]){
		if(node == -1){ // Reached parent of all(Baap of all !!)
			Paths.push_back(curr_path);
			return;
		}
		
		// Traversing parents of "node" i.e, words that can be reached from current word given the condition
		for(int p: parent[node]){ 
			curr_path.push_back(p);
			shortestPaths(p, Paths, curr_path, parent);
			curr_path.pop_back();
		}
	}

	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		// Indexes of beginWord and endWord respectively in wordList
		int start=-1, end=-1;

		for(int i=0; i<wordList.size(); i++){
			if(wordList[i] == beginWord)
				start = i;
			if(wordList[i] == endWord)
				end = i;
		}

		if(end == -1)
			return {};

		if(start == -1){
			wordList.emplace(wordList.begin(), beginWord); // setting beginWord as 1st element of wordList
			start = 0;
			end++;
		}

		int n = wordList.size();
		vector<vector<int>> graph(n, vector<int>());

		// Creating adjency list for each pair of words that can be next i.e, word with only one uncommon char from current word
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(canBeNext(wordList[i], wordList[j])){
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}

		// Apply BFS to get a list of parent of word as index 
		vector<int> parent[n];
		bfs(graph, parent, n, start, end);

		
		vector<vector<int>> Paths;
		vector<int> curr_path;
		shortestPaths(end, Paths, curr_path, parent);

		
		vector<vector<string>> ans;

		for(auto path: Paths){
			vector<string> curr;

			for(int i=0; i<path.size()-1; i++)
				curr.push_back(wordList[path[i]]);
			
			
			reverse(curr.begin(), curr.end());  
			curr.push_back(wordList[end]);
			ans.push_back(curr);
		}

		return ans;
	}
};
