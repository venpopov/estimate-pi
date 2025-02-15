#include <iostream>
#include <vector>
#include <random>
#include <cmath>

struct Point {
  double x;
  double y;
};

inline double square(double x) {
  return pow(x, 2);
}

inline double sqrt(double x) {
  return pow(x, 0.5);
}

bool is_point_in_circle(Point p, double radius = 1) {
  double distance_from_center = sqrt(square(p.x) + square(p.y));
  return distance_from_center <= radius;
}

Point random_point_in_unit_square() {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  static std::uniform_real_distribution<double> dist(-1, 1);
  return Point{dist(gen), dist(gen)};
}


int main() {
  double input;
  std::cout << "How many samples to take for estimating pi?\n";
  std::cin >> input;
  int iterations = static_cast<int>(input);
  
  int accepted_count = 0;
  Point point;
  for (int i = 0; i < iterations; ++i) {
    point = random_point_in_unit_square();
    if (is_point_in_circle(point)) {
      accepted_count++;
    }
  }

  double pi_estimate = 4.0 * accepted_count / iterations;
  std::cout << "Pi is approximately " << pi_estimate << '\n';
  
  return 0;
}
