class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        vector<string> currentWords;
        int currentLength = 0;
        string currentSentence = "";
        int n = words.size();
        for(int i = 0 ; i < n; i++){
            if(currentLength + currentWords.size() + words[i].length() > maxWidth) {
                int nLine = currentWords.size();
                int remainingLength = maxWidth - currentLength;
                int spaces = remainingLength / max(1,nLine - 1);
                int extraSpace = remainingLength % max(1, nLine - 1);
                for(int j = 0; j < max(1, nLine - 1); j++){
                    currentSentence += currentWords[j];
                    for(int k = 0; k < spaces; k++){
                        currentSentence += " ";
                    }
                    if(extraSpace > 0){
                        currentSentence += " ";
                        extraSpace -= 1;
                    }
                }
                if(nLine > 1){
                    currentSentence += currentWords[nLine - 1];
                }
                result.push_back(currentSentence);
                currentSentence = "";
                currentWords.clear();
                currentLength = 0;
            }
            currentWords.push_back(words[i]);
            currentLength += words[i].length();
        }
        currentLength = 0;
        for(int i = 0; i < currentWords.size(); i++){
            currentSentence += currentWords[i] + " ";
        }
        currentSentence.pop_back();
        currentLength += currentSentence.length();
        for(int i = 0; i < maxWidth - currentLength; i++){
            currentSentence += " ";
        }
         result.push_back(currentSentence);
         return result;
    }
};