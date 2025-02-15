#include <cmath>
#include <iostream>
#include <random>
#include <vector>

struct Point {
  double x;
  double y;
};

bool is_point_in_circle(Point p) { return (p.x * p.x + p.y * p.y) <= 1; }

Point random_point_in_square() {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  static std::uniform_real_distribution<double> dist(0, 1);
  return Point{dist(gen), dist(gen)};
}

int main() {
  std::cout << "How many samples to take for estimating pi?\n";

  double input;
  if (!(std::cin >> input) || input <= 0 ||
      input > std::numeric_limits<int>::max()) {
    std::cerr << "Please enter a positive number within integer range\n";
    return 1;
  }

  int iterations = static_cast<int>(input);

  int accepted_count = 0;
  for (int i = 0; i < iterations; ++i) {
    if (is_point_in_circle(random_point_in_square())) {
      ++accepted_count;
    }
  }

  double pi_estimate = 4.0 * accepted_count / iterations;
  std::cout << "Pi is approximately " << pi_estimate << '\n';

  return 0;
}
