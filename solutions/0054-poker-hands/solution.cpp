#include<bits/stdc++.h>
using namespace std;

// Convert a card value character to a number (2..14, where J=11, Q=12, K=13, A=14).
int cardValue(char c)
{
    if (c == 'T') return 10;
    if (c == 'J') return 11;
    if (c == 'Q') return 12;
    if (c == 'K') return 13;
    if (c == 'A') return 14;
    return c - '0';
}

// Boolean detectors for each hand category.
bool isFlush(const vector<char>& suits)
{
    for (char s : suits)
    {
        if (s != suits[0]) return false;
    }
    return true;
}

// values are sorted ascending.
bool isStraight(const vector<int>& values)
{
    for (int i = 1; i < 5; i++)
    {
        if (values[i] != values[i - 1] + 1) return false;
    }
    return true;
}

// Score a hand as [rank, tie-break values...] so hands can be compared lexicographically.
vector<int> scoreHand(const vector<int>& cardValues, const vector<char>& suits)
{
    vector<int> values = cardValues;
    sort(values.begin(), values.end());

    bool flush = isFlush(suits);
    bool straight = isStraight(values);

    // Count occurrences of each value.
    map<int, int> freq;
    for (int v : values) freq[v]++;

    // Group values by count (descending count, then descending value).
    vector<pair<int, int>> groups; // {count, value}
    for (auto& p : freq) groups.push_back({p.second, p.first});
    sort(groups.rbegin(), groups.rend());

    // Ordered values used for tie-breaking (most significant group first).
    vector<int> ordered;
    for (auto& g : groups) ordered.push_back(g.second);

    int rank;
    if (straight && flush)                                  rank = 9; // straight flush (royal is highest straight flush)
    else if (groups[0].first == 4)                          rank = 8; // four of a kind
    else if (groups[0].first == 3 && groups[1].first == 2)  rank = 7; // full house
    else if (flush)                                         rank = 6; // flush
    else if (straight)                                      rank = 5; // straight
    else if (groups[0].first == 3)                          rank = 4; // three of a kind
    else if (groups[0].first == 2 && groups[1].first == 2)  rank = 3; // two pairs
    else if (groups[0].first == 2)                          rank = 2; // one pair
    else                                                    rank = 1; // high card

    vector<int> score;
    score.push_back(rank);
    for (int v : ordered) score.push_back(v);
    return score;
}

void solve()
{
    ifstream in("poker.txt");
    string line;
    int player1Wins = 0;

    while (getline(in, line))
    {
        if (line.empty()) continue;

        istringstream ss(line);
        string card;
        vector<int> v1, v2;
        vector<char> s1, s2;

        for (int i = 0; i < 10; i++)
        {
            ss >> card;
            if (i < 5)
            {
                v1.push_back(cardValue(card[0]));
                s1.push_back(card[1]);
            }
            else
            {
                v2.push_back(cardValue(card[0]));
                s2.push_back(card[1]);
            }
        }

        if (scoreHand(v1, s1) > scoreHand(v2, s2))
        {
            player1Wins++;
        }
    }

    cout << player1Wins << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
