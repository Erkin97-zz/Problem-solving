class Solution {
 public:
  vector<int> deckRevealedIncreasing(vector<int>& deck) {
    // Create reveal order
    deque<int> indexes;
    for (int i = 0; i < deck.size(); i++) {
      indexes.push_back(i);
    }
    // Sort deck
    int cursor_index = 0;
    sort(deck.begin(), deck.end());
    vector<int> result(deck.size());
    for (int i = 0; i < deck.size(); i++) {
      result[indexes.front()] = deck[i];
      indexes.pop_front();
      indexes.push_back(indexes.front());
      indexes.pop_front();
    }
    return result;
  }
};