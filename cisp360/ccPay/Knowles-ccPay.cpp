/*
    Credit Card Payoff
    Calculate time to pay off a credit card
    CISP360
    Michael Knowles
    September 21, 2017
*/

#include <iostream>
#include <string>
#include <cmath>

// Bonus - function prototypes
void greeting ();
std::string getName ();
float getCurrentBalance ();
float getCurrentAPR ();
float getCurrentPayment ();
int calculateMonths(float, float, float, int);
void outputResults(std::string, int, float, float, float);

int main () {
  // Variables
  const int MONTHS_IN_YEAR = 12;
  std::string name;
  float currentBalance;
  float currentAPR;
  float currentPayment;
  int months;

  greeting ();

  // Get values
  name = getName ();
  currentBalance = getCurrentBalance ();
  currentAPR = getCurrentAPR ();
  currentPayment = getCurrentPayment ();
  months = calculateMonths (currentBalance,
                            currentAPR,
                            currentPayment,
                            MONTHS_IN_YEAR);

  // Output
  std::cout << "\n";
  outputResults (name, months, currentBalance,
                 currentAPR, currentPayment);

  return 0;
}

void greeting () {
  // Output greeting
  std::cout << "This program will calculate how long it will"
    "take you to pay off your outstanding credit card.\n\n"; 
}

std::string getName () {
  // Bonus - Get the user's name
  std::string name;
  std::cout << "Enter your name: ";
  std::getline (std::cin, name);
  return name;
}

float getCurrentBalance () {
  // Get current Balance from input
  float currentBalance;
  std::cout << "Enter your credit card balance: ";
  std::cin >> currentBalance;
  return currentBalance;
}

float getCurrentAPR () {
  // Get current APR from input
  // Take whole number percentage and convert to decimal
  // 22% => 0.22
  float currentAPR;
  std::cout << "Enter your Annual Percentage Rate as Integer: ";
  std::cin >> currentAPR;
  currentAPR /= 100.00;
  std::cout << currentAPR << std::endl;
  return currentAPR;
}

float getCurrentPayment () {
  // Get current Payment from input
  float currentPayment;
  std::cout << "Enter the amount you can pay monthly: ";
  std::cin >> currentPayment;
  return currentPayment;
}

int calculateMonths (float balance, float APR, float payment,
                     int MONTHS_IN_YEAR) {
  // Calculate how long to pay off
  // n = -log(1 - (Ai/P)) / log(1 + i)
  // n = number of months needed to pay
  // A = amount on card (balance)
  // i = monthly rate (APR / 12)
  // P = monthly payment amount
  int months;
  APR /= 12;

  months = -1 * (log (1 - (balance * APR) / payment)) 
           / (log (1 + APR));

  return months;
}

void outputResults (std::string name, int months,
                    float balance, float APR, float payment) {
  // Bonus - Pretty output results
  std::cout << "Name:\t\t\t" << name << "\n"
            << "Current Balance:\t" << balance << "\n"
            << "APR:\t\t\t" << APR << "\n"
            << "Monthly Payment:\t" << payment << "\n"
            << "You will payoff your credit card in "
            << months << " months.\n";
}