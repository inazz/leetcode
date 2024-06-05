class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<int>> wildDict;
        vector<int> distances(wordList.size(), 0);
        int endIdx = -1;
        for (int i = 0; i < wordList.size(); i++) {
            const string &word = wordList[i];
            if (word == endWord)
                endIdx = i;
            for (int j = 0; j < word.size(); j++) {
                string wildWord = word;
                wildWord[j] = '*';
                if (wildDict.find(wildWord) == wildDict.end())
                    wildDict[wildWord] = vector<int>();
                wildDict[wildWord].push_back(i);
            }
        }
        if (endIdx == -1)
            return 0;
        deque<pair<string, int>> q; // pair(word, distance)
        q.push_back(make_pair(beginWord, 1));
        while(!q.empty() && distances[endIdx] == 0) {
            pair<string, int> word_distance = q.front();
            q.pop_front();
            string word = word_distance.first;
            int distance = word_distance.second;
            for (int i=0; i<word.size(); i++) {
                string wildWord = word;
                wildWord[i] = '*';
                map<string, vector<int>>::iterator itr = wildDict.find(wildWord);
                if (itr == wildDict.end())
                    continue;
                const vector<int> &nextIndices = itr->second;
                for (int nextIdx: nextIndices) {
                    if (distances[nextIdx] != 0)
                        continue;
                    distances[nextIdx] = distance + 1;
                    if (nextIdx == endIdx)
                        break;
                    q.push_back(make_pair(wordList[nextIdx], distance + 1));
                }
                // don't want to visit this wild again. let's remove from dict.
                wildDict.erase(itr);
            }
        }
        return distances[endIdx];
    }
};
