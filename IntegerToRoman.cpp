#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
	const static char* pattern[]; 
	const static char* roman_digit[];
public:
	string intToRoman(int num) {
		if (num < 1 || num > 3999) return "";
		string res("");
		int i=0;
		while (num) {
			res = getSingleRomanDigit(num % 10, i++) + res;
			num /= 10;
		}
		return res; 
	}

	string getSingleRomanDigit(int digit, int mag) {
		if (digit == 0) return "";
		if (digit > 9 || digit < 1 || mag > 3 || mag < 0) {
			return "FORMAT ERROR";
		}
		string res;
		int pi = 0;
		for (int i=0; (pi = pattern[digit][i]) != '\0'; i++) {
			pi = pi - '0';
			res.push_back(roman_digit[mag][pi]);
		}
		return res;
	}
};
const char* Solution::pattern[] =  {"x", "0", "00", "000", "01", "1", "10", "100", "1000", "02"};
const char* Solution::roman_digit[] = {"IVX", "XLC", "CDM", "M"};

int main() {
	Solution s;
	for (int i=1; i<120; i++) {
		cout<<i<<":"<<s.intToRoman(i)<<endl;
	}
	return 0;
}
