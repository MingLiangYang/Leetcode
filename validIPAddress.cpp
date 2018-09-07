/*
编写一个函数来验证输入的字符串是否是有效的 IPv4 或 IPv6 地址。

IPv4 地址由十进制数和点来表示，每个地址包含4个十进制数，其范围为 0 - 255， 用(".")分割。比如，172.16.254.1；

同时，IPv4 地址内的数不会以 0 开头。比如，地址 172.16.254.01 是不合法的。

IPv6 地址由8组16进制的数字来表示，每组表示 16 比特。这些组数字通过 (":")分割。比如,  2001:0db8:85a3:0000:0000:8a2e:0370:7334 是一个有效的地址。而且，我们可以加入一些以 0 开头的数字，字母可以使用大写，也可以是小写。所以， 2001:db8:85a3:0:0:8A2E:0370:7334 也是一个有效的 IPv6 address地址 (即，忽略 0 开头，忽略大小写)。

然而，我们不能因为某个组的值为 0，而使用一个空的组，以至于出现 (::) 的情况。 比如， 2001:0db8:85a3::8A2E:0370:7334 是无效的 IPv6 地址。

同时，在 IPv6 地址中，多余的 0 也是不被允许的。比如， 02001:0db8:85a3:0000:0000:8a2e:0370:7334 是无效的。

说明: 你可以认为给定的字符串里没有空格或者其他特殊字符。

思路：臃肿但不困难，分成多个函数即可。#Todo 化简结构，缩短代码行数  #have done
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
/*
	vector<string> split(string a, string pattern){
		int pos = 0;
		a += pattern;
		vector<string> res;
		while (pos < a.size()){
			int pos2 = a.find(pattern, pos);
			res.push_back(a.substr(pos , pos2 - pos));
			pos = pos2+1;
		}
		return res;
	}
	//一种更nice的表达，在处理的string后边加一个pattern，无需特殊处理第一段，更有效率一点。
*/
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
