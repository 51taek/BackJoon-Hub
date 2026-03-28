#include <string>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct WordInfo {
    int st;
    int en;
    string word;
    bool spoiled;
};

vector<WordInfo> words;
set<string> visible_words;
set<string> opened_words;
int ans = 0;

void parse_words(string message, vector<bool>& covered) {
    int n = message.size();
    int i = 0;

    while (i < n) {
        if (message[i] == ' ') {
            i++;
            continue;
        }

        int st = i;
        string w = "";
        bool spoiled = false;

        while (i < n && message[i] != ' ') {
            w += message[i];
            if (covered[i]) spoiled = true;
            i++;
        }

        int en = i - 1;
        words.push_back({st, en, w, spoiled});

        if (!spoiled) {
            visible_words.insert(w);
        }
    }
}

void open_words(vector<vector<int>>& spoiler_ranges) {
    for (int i = 0; i < spoiler_ranges.size(); i++) {
        int l = spoiler_ranges[i][0];
        int r = spoiler_ranges[i][1];

        for (int j = 0; j < words.size(); j++) {
            int st = words[j].st;
            int en = words[j].en;
            string w = words[j].word;

            if (max(l, st) <= min(r, en)) {
                if (words[j].spoiled &&
                    visible_words.find(w) == visible_words.end() &&
                    opened_words.find(w) == opened_words.end()) {
                    ans++;
                    opened_words.insert(w);
                }
            }
        }
    }
}

int solution(string message, vector<vector<int>> spoiler_ranges) {
    words.clear();
    visible_words.clear();
    opened_words.clear();
    ans = 0;

    vector<bool> covered(message.size(), false);

    for (int i = 0; i < spoiler_ranges.size(); i++) {
        int l = spoiler_ranges[i][0];
        int r = spoiler_ranges[i][1];
        for (int j = l; j <= r; j++) {
            covered[j] = true;
        }
    }

    parse_words(message, covered);
    open_words(spoiler_ranges);

    return ans;
}