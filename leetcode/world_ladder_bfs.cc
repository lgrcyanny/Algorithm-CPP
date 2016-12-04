#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_set>
#include <climits>
#include <cstdlib>
#include <sstream>
#include <fstream>
using namespace std;


class Solution {
private:
  struct Node {
    string s;
    int distance; // The distance from start to the current node
    Node():s(), distance(0) {}
    Node(string vstr):s(vstr), distance(0){ }
    Node(string vstr, int vdistance):s(vstr), distance(vdistance) {}
  };
  queue<Node*> visited_queue;

public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
      if (compare(start, end) >= 0) {
        return 2;
      } else if (dict.empty()) {
        return 0;
      }
      int length = 0;
      Node* root = new Node(start);
      visited_queue.push(root);
      dict.erase(start);
      dict.erase(end);
      while (!visited_queue.empty() && !dict.empty()) {
        Node* t_node = visited_queue.front();
        string t_str = t_node->s;

        for (int i = 0; i < t_str.length(); i++) {
          char a = t_str[i];
          for (char c = 'a'; c <= 'z'; c++) {
            if (c != a) {
              t_str[i] = c;
              if (t_str == end) {
                return t_node->distance + 2;
              } else if (dict.find(t_str) != dict.end()) {
                // find the word in the dict
                Node* new_node = new Node(t_str, t_node->distance + 1);
                visited_queue.push(new_node);
                dict.erase(t_str);
              }
            }
          }
          t_str[i] = a;
        }
        visited_queue.pop();
        delete t_node;
      }

      while (!visited_queue.empty()) {
        Node* f = visited_queue.front();
        if (compare(f->s, end) >= 0) {
          length = f->distance + 2;
          break;
        }
        visited_queue.pop();
        delete f;
      }

      return length;
    }


    int compare(const string &a, const string &b) {
        int index = -1;
        if (!a.empty() && !b.empty() && a.length() == b.length()) {
           int len = a.length();
           for (int i = 0; i < len; i++) {
                if (a[i] == b[i]) {
                    continue;
                } else if (index == -1 && a[i] != b[i]) {
                    index = i;
                } else if (index >= 0 && a[i] != b[i]) {
                    index = -1;
                    break;
                }
            }
        }
        return index;
    }
};


int main(int argc, char const *argv[])
{
  string start("nanny");
  string end("aloud");
   unordered_set<string> dict;
  ifstream infine("world_ladder.dat");
  string line;
  while (getline(infine, line)) {
    dict.insert(line);
  }
  // dict.insert("hot");
  // dict.insert("dog");
  // dict.insert("dot");
  // dict.insert("dog");
  // dict.insert("lot");
  // dict.insert("log");
  Solution s;
  int length = s.ladderLength(start, end, dict);
  cout << "shortest length = " << length << endl;
  return 0;
}




