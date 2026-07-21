#include "../include/greeks.hpp"
#include "../include/blackScholes.hpp"

double Greeks::delta(const Option &option) {
  double d = BlackScholes::calcD1(option);
  if (option.getOptionType() == OptionType::Call) {
    return BlackScholes::normalCDF(d);
  }
  return BlackScholes::normalCDF(d) - 1;
}
