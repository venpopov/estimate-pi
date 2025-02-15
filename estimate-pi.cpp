#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>

struct Point {
  const double x;
  const double y;
};

Point random_point_in_square() {
  thread_local static std::mt19937 gen(std::random_device{}());
  static std::uniform_real_distribution<double> dist(0, 1);
  return Point{dist(gen), dist(gen)};
}

bool is_point_in_circle(Point p) { return (p.x * p.x + p.y * p.y) <= 1; }

auto validate_input(std::istream& in) {
  double input;
  if (!(in >> input) || input <= 0) {
    std::cerr << "Input should be a positive integer in decimal or scientific notation\n";
    std::exit(1);
  }

  return static_cast<size_t>(input);
}

int main() {
  std::cout << "How many samples to take for estimating pi?\n";

  const size_t iterations = validate_input(std::cin);
  size_t accepted_count = 0;
  for (size_t i = 0; i < iterations; ++i) {
    if (is_point_in_circle(random_point_in_square())) {
      ++accepted_count;
    }
  }

  double pi_estimate = 4.0 * accepted_count / iterations;
  std::cout << "Pi is approximately " << std::setprecision(10) << pi_estimate << '\n';

  return 0;
}
