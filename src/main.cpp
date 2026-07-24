#include "../include/blackScholes.hpp"
#include "../include/greeks.hpp"
#include "../include/impliedVolatility.hpp"
#include <iostream>
using namespace std;
int main() {

  Option call(100, 100, 1.0, 0.20, 0.05, OptionType::Call);
  Option put(100, 100, 1.0, 0.20, 0.05, OptionType::Put);
  double mk = BlackScholes::price(call);
  std::cout << mk << '\n';
  std::cout << ImpliedVolatility::calc_iv(call, mk) << '\n';
}
