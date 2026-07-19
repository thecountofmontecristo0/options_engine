#include "../include/blackScholes.hpp"
#include <iostream>

using namespace std;
int main() {

  Option call(100, 100, 1.0, 0.20, 0.05, OptionType::Call);

  std::cout << BlackScholes::price(call) << '\n';
}
