#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

enum ParseState {
  S_START = 0,
  S_TAG_START = 1,
  S_TAG = 2,
  S_KEY_START = 3,
  S_KEY = 4,
  S_EQUAL_BEGIN = 5,
  S_VALUE_START = 6,
  S_VALUE = 7,
  S_END = 8
};

struct TagParser {
  string tag;
  vector<string> tokens;

  ParseState parse(const std::string &str) {
    ParseState st = S_START;

    int i = 0, l = 0;
    for (l = 0, i = 0; i < str.size(); ++i) {
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
        } else if (isalpha(c) || isdigit(c)) {
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
          st = isspace(c) ? S_EQUAL_BEGIN : S_VALUE_START;
          tokens.push_back(str.substr(l, i - l));
        } else if (isalpha(c) || isdigit(c)) {
          st = S_KEY;
        } else {
          goto error;
        }
        break;

      case S_EQUAL_BEGIN:
        if (isspace(c)) {
          st = S_EQUAL_BEGIN;
        } else if (c == '=') {
          st = S_VALUE_START;
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
    return st;
  error:
    return st;
  }
};

int main() {
  int i = 0;
  string line = "<tag v1 = \"1 23\" v2 = \"43.4\" v3 = \"hello\">";
  ParseState st;
  TagParser tp;

  while (getline(cin, line)) {
    TagParser tp;

    if ((st = tp.parse(line)) == S_END) {
      cout << i << " Parse OK: " << line << endl;
      cout << " \t " << tp.tag << " ";

      for (int k = 0; k < tp.tokens.size(); k += 2) {
        cout << "#" << tp.tokens[k] << "# = #" << tp.tokens[k + 1] << "#\t";
      }
      cout << endl;
    } else {
      cout << i << " Parse Error: " << st << " " << line << endl;
    }
    ++i;
  }

  return 0;
}

