#include "StackCalculator2.h"

double StackCalculator2::operator()(const string& exp) {
	transform(exp, vs);
	
	stack<double> sd;
	for (const auto& s : vs) {
		if (s.tag == S::NUM) {
			sd.push(s.d);
		}
		else {
			double d2 = sd.top();
			sd.pop();
			double d1 = sd.top();
			sd.pop();
			sd.push(calc(s.c, d1, d2));
		}
	}
	
	return sd.top();
}

bool StackCalculator2::precede(char c1, char c2) {
	struct PRI {
		char c;
		int p;
	} const pri[] = { { '=', -1 },{ '(', 0 },{ '+', 1 },{ '-', 1 },\
	{ ')', 2 },{ '*', 2 },{ '/', 2 } };
	
	auto it1 = find_if(begin(pri), end(pri), [c1](const PRI& op) { return op.c == c1; });
	auto it2 = find_if(begin(pri), end(pri), [c2](const PRI& op) { return op.c == c2; });
	return it1->p > it2->p;
}

double StackCalculator2::calc(char op, double d1, double d2) {
	switch (op) {

	}
}

void StackCalculator2::transform(const string& exp, vector<S>& vs) {
	stack<char> sp;
	sp.push('=');
	
	string num = "";
	for (const char& ch : exp) {
		if (ch >= '0' && ch <= '9' || ch == '.') {
			num += ch;
		}
		else {
			if (num != "") {
				vs.push_back(atof(num.c_str()));
				num = "";
			}
			if (ch == ' ') continue;
			switch (ch) {
				case '(': 
					sp.push(ch); break;
				case ')': 
					while (sp.top() != '(') {
						vs.push_back(sp.top());
						sp.pop();
					}
					sp.pop();
					break;
				default : 
					while (precede(sp.top(), ch)) {
						vs.push_back(sp.top());
						sp.pop();
					}
					if (ch != '=') sp.push(ch);
					break;
			}
		}
	}
}
