#ifndef OPTION_HPP
#define OPTION_HPP

enum class OptionType {
  Call,
  Put,
};

class Option {
private:
  double spotPrice;
  double volatility;
  double riskFreeRate;

  double strikePrice;
  double timeToExpiry;
  OptionType optionType;

public:
  Option(double spot, double strike, double iv, double time, double rate,
         OptionType type);

  double getSpotPrice() const;
  double getStrikePrice() const;
  double getTimeToExpiry() const;
  double getIv() const;
  double getRiskFreeRate() const;
  OptionType getOptionType() const;

  void setSpotPrice(double spot);
  void setStrikePrice(double strike);
  void setTimeToExpiry(double time);
  void setIv(double iv);
  void setRiskFreeRate(double risk);
};
#endif
