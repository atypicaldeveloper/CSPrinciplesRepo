// indexOnList.cpp - find index on list

#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

int main() {
  // Create a vector for the random numbers
  std::vector<int> numbers;
  // Request vector capacity of 20 - improves performance
  numbers.reserve(20);
  // Create a A Mersenne Twister generator using a true random number seed from
  // random_device
  std::mt19937_64 gen(std::random_device{}());

  // Define the range of the random numbers (1 to 999)
  std::uniform_int_distribution<> dis(1, 999);

  // Generate a random number 100 times, then add them to the vector
  for (int i = 0; i < 100; i++) {
    numbers.push_back(dis(gen));
  }

  // Print the original list
  std::cout << "Original list: ";

  // Write the original list to the output stream using ostream_iterator
  std::copy(numbers.begin(), numbers.end(),
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl << std::endl;

  // Sort the numbers
  std::sort(numbers.begin(), numbers.end());

  // Print the sorted list
  std::cout << "Sorted list: ";

  // Write the sorted list to the output stream using ostream_iterator
  std::copy(numbers.begin(), numbers.end(),
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl << std::endl;

  int answer;

  // Print a query for an index
  std::cout << "Enter desired index..." << std::endl;
  std::cin >> answer;
  // Print the index
  std::cout << "Value at desired index: ";
  int output = numbers.at(answer);
  std::cout << output << std::endl;

  return 0;
}