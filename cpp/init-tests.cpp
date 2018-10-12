#include <iostream>
#include <string>


class Test {
public:
	int n {10};
	int t {100};

	std::string s;

	Test(std::string ss) : n(99), s(ss) {}
};

int main() {
	Test t("erere");
	std::cout << t.n << "\n" << t.t << "\n" << t.s << std::endl;

	return 0;
}