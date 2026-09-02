class Solution {
public:
    string getHint(string secret, string guess) {
        int secretcount[10];
        int guesscount[10];
        int bulls = 0;
        int cows = 0;

        for (int i = 0; i < 10; i++) {
            secretcount[i] = 0;
            guesscount[i] = 0;
        }

        for (int j = 0; j < secret.length(); j++) {
            if (secret[j] == guess[j]) {
                bulls += 1;
            } else {
                secretcount[secret[j] - '0'] += 1;
                guesscount[guess[j] - '0'] += 1;
            }
        }

        for (int p = 0; p < 10; p++) {
            cows += min(secretcount[p], guesscount[p]);
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};