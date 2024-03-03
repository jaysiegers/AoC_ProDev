#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <algorithm>
using namespace std;

vector<vector<char>> parse(ifstream &input) {
    string s;
    getline(input, s);
    int n = (s.size() + 1) / 4;
    vector<vector<char>> ans(n);
    while(s[1] != '1') {
        for(int i = 0; i < n; i++)
            if(s[1 + i * 4] != ' ') ans[i].push_back(s[1 + i * 4]);
        getline(input, s);
    }
    getline(input, s);
    for(int i = 0; i < n; i++) reverse(ans[i].begin(), ans[i].end());
    return ans;
}

int main () {
    ifstream input;
    input.open("5-01-input.txt");
    vector<vector<char>> state = parse(input);
    int a, s, e;
    string f;
    while(input >> f) {
        input >> a >> f >> s >> f >> e;
        s -= 1, e -= 1;
        while(a--){
            state[e].push_back(state[s].back());
            state[s].pop_back();
        }
    }
    for(int i = 0; i < state.size(); i++) cout << state[i].back();
    cout << endl;
    return 0;
}