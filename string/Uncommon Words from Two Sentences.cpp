/*

给定两个句子 A 和 B 。 （句子是一串由空格分隔的单词。每个单词仅由小写字母组成。）

如果一个单词在其中一个句子中只出现一次，在另一个句子中却没有出现，那么这个单词就是不常见的。

返回所有不常用单词的列表。您可以按任何顺序返回列表。

分析：即两个字符串只出现一次的单词。

思路：使用set<string>容器找出重复元素，并做差即可。可使用str.find()和str.substr()函数来做str.split()。注意substr()第二个参数是子串长度。
*/
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
