#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<string>
//#include<hash_map>
#include<algorithm>
//#include<iostream>
using namespace std;

class Solution {
public:
	vector<string> uncommonFromSentences(string A, string B) {
		string C = A + " " + B + " ";
		set<string> res;
		set<string> res1;
		int pos = 0;
		while (pos < C.size()){
			int pos2 = C.find(" ", pos);
			string s = C.substr(pos, pos2 - pos);
			if (res.count(s)) 
				res1.insert(s);
			else 
				res.insert(s);
			pos = pos2+1;
		}
		for (set<string>::iterator it = res1.begin(); it != res1.end(); it++){
			res.erase(*it);
		}
		vector<string> a(res.size());
		copy(res.begin(),res.end(),a.begin());
		return a;
	}

};

int main(){
	Solution s;
	vector<string> res = s.uncommonFromSentences("apple apple", "banana");
	for (int i = 0; i < res.size(); i++){
		cout << res[i];
	}
	while (1);
	return 0;
}