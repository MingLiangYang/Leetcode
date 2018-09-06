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
	string validIPAddress(string IP) {
		if (IP.empty())return "Neither";
		if (IPV4(IP))return "IPv4";
		else if (IPV6(IP))return "IPv6";
		else return "Neither";
	}
private:
	bool IPV4(string IP){
		vector<string> a = split(IP, ".");
		if (a.size() != 4) return false;
		for (int i = 0; i < a.size(); i++){
			if (a[i].empty()) return false;
			else{//judge ipv4
				if (!judgenumber_ipv4(a[i])){
					return false;
				}
				else{
					int num = atoi(a[i].c_str());
					if (!(num >= 0 && num <= 255)){
						return false;
					}
				}
			}
		}
		return true;
	}
	bool IPV6(string IP){
		vector<string> res = split(IP, ":");
		if (res.size() != 8) return false;
		for (int i = 0; i < res.size(); i++){
			if (res[i].empty())return false;
			else{//judge ipv6
				if (!judegepart_ipv6(res[i])){
					return false;
				}
			}
		}
		return true;
	}
	vector<string> split(string a, string pattern){
		int pos = 0;
		vector<string> res;
		while (pos < a.size()){
			int pos2 = a.find(pattern, pos + 1);
			if (pos == 0) res.push_back(a.substr(pos, pos2));
			else res.push_back(a.substr(pos + 1, pos2 - pos - 1));
			pos = pos2;
		}
		return res;
	}
	bool judgenumber_ipv4(string part){
		for (int i = 0; i < part.size(); i++){
			//if (i==0 && part[])
			if (part[0] == '0') return false;
			if ('0' > part[i] || part[i] > '9'){
				return false;
			}
		}
		return true;
	}
	bool judegepart_ipv6(string part){
		if (part.size() > 4) return false;
		for (int i = 0; i < part.size(); i++){
			char a = part[i];
			if (!((a >= '0'&&a <= '9') || (a >= 'a'&&a <= 'f') || (a >= 'A'&&a <= 'F')))return false;
		}
		return true;
	}
};

int main(){
	Solution s;
	string input;
	cin >> input;
	cout<< s.validIPAddress(input);

	while (1);
	return 0;
}