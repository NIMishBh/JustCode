#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	vector<int> arr;
    stringstream sstr(str);
    char ch;
    int samp;
    while(sstr)
    {
        sstr>>samp>>ch;
        arr.push_back(samp);
    }
    return arr;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    return 0;
}
