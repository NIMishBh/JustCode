#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

int main() {
    int n, q;
    string curr = "", attr_name;
    map<string, string> m;
    cin >> n >> q;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string line, tag, extract;
        getline(cin, line);
        stringstream ss(line);

        // Process the HRML lines
        while(getline(ss, extract, ' ')) {
            // If it's a tag
            if (extract[0] == '<') {
                // If it's an opening tag
                if (extract[1] != '/') {
                    // Remove the opening bracket
                    tag = extract.substr(1);
                    // For tags without attributes
                    if (tag[tag.length() - 1] == '>') {
                        tag.pop_back();
                    }
                    // Check if any nesting is needed
                    if (curr.size() > 0) {
                        // Nest this tag
                        curr += "." + tag;
                    }
                    else {
                        curr = tag;
                    }
                }
                // If it's a closing tag
                else {
                    tag = extract.substr(2, (extract.find('>') - 2));
                    // Check if a nested tag has to be closed
                    size_t pos = curr.find("." + tag);
                    if (pos != string::npos) {
                        // Remove the nested tag
                        curr = curr.substr(0, pos);
                    }
                    else {
                        // All tags are closed
                        curr = "";
                    }
                }
            }

            else if (extract[0] == '"') {
                size_t pos = extract.find_last_of('"');
                string attr_value = extract.substr(1, pos-1);
                m[attr_name] = attr_value;
            }

            else {
                if (extract != "=") {
                    attr_name = curr + "~" + extract;
                }
            }
        }
    }
    string query;
    for (int i = 0; i < q; i++) {
        getline(cin, query);

        // Search in the map
        map<string, string>::iterator itrate = m.find(query);
        if (itrate != m.end()) {
            cout << itrate->second << endl;
        }
        else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}