#include <memory>
#include <string>


class Investment {
	int value;
};

class Bond : public Investment {
	double d;
public:
	Bond(double d) : d(d) {};
};

class RealEstate : public Investment {
	std::string u;
public:
	RealEstate(std::string u) : u(u) {};
};

template<typename... Ts>
std::unique_ptr<Investment> makeInvestment(Ts&&... params) {
	std::unique_ptr<Investment> p(new Bond(std::forward<Ts>(params)...));

	// bool flag = true;
	// if (flag) {
	// 	p.reset(new Bond(std::forward<Ts>(params)...));
	// } else {
	// 	p.reset(new RealEstate(std::forward<Ts>(params)...));
	// }
	return p;
}

int main(int argc, char const *argv[])
{
	auto inv = makeInvestment(1.0);
	return 0;
}
