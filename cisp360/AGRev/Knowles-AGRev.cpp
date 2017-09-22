/*
    Al Gore's Revenge
    Calculate the effects of climate change
    CISP360
    Michael Knowles
    September 9, 2017
*/

#include <iostream>
#include <string>

class Ocean {
  float mm;
public:
  Ocean(float);
  float cm, in;
};

Ocean::Ocean(float o) : mm(o) {
  // 1 mm = 0.1 cm = 0.03937 in
  cm = mm * 0.1;
  in = mm * 0.03937;
}

class Temperature {
  float current;
  const float risePer15 = 0.02;
public:
  Temperature(float, std::string);
  std::string city;
  float calculateRise(int);
};

Temperature::Temperature(float t, std::string c) : current(t), city(c) {}; 

float Temperature::calculateRise(int years) {
  // Calculate rise in temperature
  return (current + (current * risePer15 * years));
};

void welcome() {
  // Display a welcome message at program start
  std::cout << "Exploration of the changing weather.\n\n";
}

void pastOceanRise(Ocean rise) {
  // How much the world's oceans rose over the last 100 years
  std::cout << "The world's oceans rose over the last 100 years, by\n"
	    << rise.in << " inches or "
	    << rise.cm << " centimeters\n\n";
}

void futureOceanRise(Ocean rise, int years) {
  // How much the oceans will rise over the next 15/30 years
  std::cout << "In " << years << " years, the oceans will have risen by\n"
	    << rise.in * years << " inches or "
	    << rise.cm * years << " centimeters\n\n";
}

void futureTemps(Temperature *cities, int years, std::string month) {
  // How much the mean July temps will increase over the next 15/30 years
  std::string yearString;
  if (years == 0) {
    yearString = "today";
  } else {
    yearString = "+" + std::to_string(years) + " years";
  };

  int arraySize = (sizeof(*cities) / sizeof(cities)) - 1;

  std::cout << "Average " << month << " Temperatures, " << yearString << "\n";
  for(int i = 0; i < arraySize; i++) {
    std::cout << cities[i].city << ": "
	      << cities[i].calculateRise(years) << "\n";
  };
  std::cout << "\n";
}

void printAdvice() {
  std::cout << "Climate is changing!\n"
	    << "Listen to Al Gore!\n\n";
}

int main() {
  // Variables
  const Ocean oceanRiseInPastCentury{1.8}; // mm
  const Ocean oceanRisePerYear{3.1};       // mm
  Temperature citiesJuly[] = { // F in July
    Temperature{85, "New York City"},
    Temperature{88, "Denver"},
    Temperature{106, "Phoenix"},
    Temperature{92, "Sacramento"}
  };

  welcome();

  // Specification 1
  pastOceanRise(oceanRiseInPastCentury);
  // Specification 2
  futureOceanRise(oceanRisePerYear, 15);
  futureOceanRise(oceanRisePerYear, 30);
  // Specification 3
  futureTemps(citiesJuly, 15, "July");
  futureTemps(citiesJuly, 30, "July");

  // Bonus - Calculate as many years as we want
  int bonusYears[5];
  for(int i = 0; i < 5; i++) {
    bonusYears[i] = 30 + (15 * (i + 1));
    futureOceanRise(oceanRisePerYear, bonusYears[i]);
    futureTemps(citiesJuly, bonusYears[i], "July");
  }

  // Bonus - Cities in January
  Temperature citiesJanuary[] = { // F in January
    Temperature{35, "New York City"},
    Temperature{33, "Denver"},
    Temperature{57, "Phoenix"},
    Temperature{47, "Sacramento"}
  };
  futureTemps(citiesJanuary, 15, "January");
  futureTemps(citiesJanuary, 30, "January");

  // Bonus - Give advice
  printAdvice();

  return 0;
}
