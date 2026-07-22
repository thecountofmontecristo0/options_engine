#include "../include/blackScholes.hpp"
#include "../include/greeks.hpp"
#include <iostream>
using namespace std;
int main() {

  Option call(100, 100, 1.0, 0.20, 0.05, OptionType::Call);
  Option put(100, 100, 1.0, 0.20, 0.05, OptionType::Put);

  std::cout << Greeks::theta(call) << '\n';
  std::cout << Greeks::theta(put) << '\n';
}
