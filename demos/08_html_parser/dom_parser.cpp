#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

enum ParseState {
  S_START = 0,
  S_TAG_START,
  S_TAG,
  S_KEY_START,
  S_KEY,
  S_VALUE_START,
  S_VALUE,
  S_END
};

struct TagParser {
  string tag;
  vector<string> tokens;

  bool parse(const std::string &str) {
    ParseState st = S_START;

    for (int l = 0, i = 0; i < str.size(); ++i) {
      char c = str[i];

      switch (st) {
      case S_START:
        if (isspace(c)) {
          st = S_START;
        } else if (c == '<') {
          st = S_TAG_START;
        } else {
          goto error;
        }
        break;

      case S_TAG_START:
        if (isspace(c)) {
          st = S_TAG_START;
        } else if (isalpha(c)) {
          l = i;
          st = S_TAG;
        } else {
          goto error;
        }
        break;

      case S_TAG:
        if (isspace(c)) {
          tag = str.substr(l, i - l);
          st = S_KEY_START;
        } else if (isalpha(c)) {
          st = S_TAG;
        } else {
          goto error;
        }
        break;

      case S_KEY_START:
        if (isspace(c)) {
          st = S_KEY_START;
        } else if (isalpha(c)) {
          st = S_KEY;
          l = i;
        } else if (c == '>') {
          st = S_END;
        } else {
          goto error;
        }
        break;

      case S_KEY:
        if (isspace(c) || c == '=') {
          st = S_VALUE_START;
        } else if (isalpha(c)) {
          st = S_KEY;
        } else {
          goto error;
        }
        break;

      case S_VALUE_START:
        if (isspace(c)) {
          st = S_VALUE_START;
        } else if (c == '"') {
          st = S_VALUE;
          l = i + 1;
        } else {
          goto error;
        }
        break;

      case S_VALUE:
        if (c == '"') {
          tokens.push_back(str.substr(l, i - l));
          st = S_KEY_START;
        } else {
          st = S_VALUE;
        }
        break;

      case S_END:
        break;
      default:
        goto error;
      } // switch
    }   // for

    return st == S_END;
  error:
    return false;
  }
};

struct Node {
    Node(const string& tag):tag(tag) {}
    
    string tag;
    unordered_map<string, const string> atrributes_map;    
    unordered_map<string, Node*> children_map;
};

string trim(const string& token) {
    int i = 0, j = token.size() - 1;
    while (i < token.size() && token[i] == ' ') ++i;
    if (token[i] == '"') ++i;
    
    while (j >= 0 && token[j] == ' ') --j;
    if (token[j] == '"') --j;
    
    return token.substr(i, j - i + 1);
}

void tokenize(const string& str, int start, vector<string>& tokens) {
    string token;
    int l = start, i = start;
    for (; i < str.size() - 1; ++i) {
      if (str[i] == '=' || str[i] == ' ') {
        token = trim(str.substr(l, i - l));

        if (!token.empty()) {
          tokens.push_back(trim(token));
        }

        l = i + 1;
      }
    }

    token = str.substr(l, i - l);
    tokens.push_back(trim(token));

    for (auto &t : tokens) {
        cout << "#" << t << "#" << endl;
    }
}

struct DomTree {
   Node root; 
   stack<Node*> stack_;
   vector<string> tokens;
   
   DomTree():root("") {
    stack_.push(&root);
   }
   
   ~DomTree() {
    destory(root.children_map);
   }
   
   string query(const std::string& q) {
    int start = 0, i = 0;
    Node *p = &root;
    string tag, attr;
    for (;i < q.size(); ++i) {
        if (q[i] == '.') {
                tag = q.substr(start, i - start);
                auto it = p->children_map.find(tag);
                if (it == p->children_map.end()) {
                    return "Not Found!";
                } else {
                    p = it->second;
                }
                start = i + 1;
        } else if (q[i] == '~') {
                tag = q.substr(start, i - start);
                auto it = p->children_map.find(tag);
                if (it == p->children_map.end()) {
                    return "Not Found!";
                } else {
                    p = it->second;
                }    
                
                attr = q.substr(i + 1, q.size() - i);
                auto ait = p->atrributes_map.find(attr);
                if (ait == p->atrributes_map.end()) {
                    return "Not Found!";
                } else {
                    return ait->second;
                }
        }
    }
    return "Not Found!";
   }
   
   void destory(unordered_map<string, Node*>& map) {
    for (auto [key, val]:map) {
        destory(val->children_map);
        delete val;
    }
   }
   
   void parse_open_tag(const string& line) {
    int i = 1;
    for (; i < line.size(); ++i) {
        if (line[i] == ' ' || line[i] == '>') break;
   }
    
    Node *top = stack_.top(); 
    Node *node = new Node(line.substr(1, i - 1));
    top->children_map.insert({node->tag, node});
    stack_.push(node);
    
    if (line[i] == '>') return;
    
    tokens.clear();
    tokenize(line, i, tokens);

    for (int i = 0; i < tokens.size(); i += 2) {
        node->atrributes_map.insert({tokens[i], tokens[i+1]});
    }
   }
   
   void parse_close_tag(const string& line) {
    stack_.pop(); 
   }
   
   void parse(istream& cin, int n_lines) {
    string line;
    for (int i = 0; i < n_lines; ++i) {
        line.clear();
        getline(cin, line);
        
        if (line.empty()) continue;
        
        if (line[1] == '/') {
            parse_close_tag(line);
        } else {
            parse_open_tag(line);
        }
    }
   }
};


int main() {
    string line;
    getline(cin, line);
    istringstream sin(line);
    int m, n;
    sin >> m >> n;
    DomTree dom;
    dom.parse(cin, m);
    
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        cout << dom.query(line) << endl;
    }
    
    return 0;
}

