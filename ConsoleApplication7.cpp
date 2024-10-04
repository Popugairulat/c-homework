#include <random>
#include <iostream>

class Dice {
public:
	Dice(unsigned max, unsigned seed) :
		max(max), dstr(1, max), reng(seed) { }
		unsigned roll() {
		return dstr(reng);	
	    }
	
private:
	unsigned max;
	std::uniform_int_distribution<unsigned> dstr;
	std::default_random_engine reng;
};

class ThreeDicePool {
public:
	ThreeDicePool(unsigned max, unsigned seed_1, unsigned seed_2, unsigned seed_3)
		: dice_1(max, seed_1), dice_2(max, seed_2), dice_3(max, seed_3) {}

	unsigned roll() {
		return dice_1.roll() + dice_2.roll() + dice_3.roll();
	}

private:
	Dice dice_1, dice_2, dice_3;
	unsigned max;
	std::uniform_int_distribution<unsigned> dstr;
	std::default_random_engine reng;
};

template <typename Creature> // параметрический полиморфизм
double expected_value(Creature& d, unsigned number_of_rolls = 1) {
	auto accum = 0llu;
	for (unsigned cnt = 0; cnt != number_of_rolls; ++cnt)
		accum += d.roll();
	return
		static_cast<double>(accum) / static_cast<double>(number_of_rolls);
	
}
int main() {
	Dice d(10, 6);
	std::cout << expected_value(d)<<" ";
	std::cout << expected_value(d)<<" ";
	std::cout << expected_value(d)<<" ";
	return 0;
}