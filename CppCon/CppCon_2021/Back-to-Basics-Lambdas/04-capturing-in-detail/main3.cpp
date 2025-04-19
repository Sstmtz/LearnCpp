// Lambdas: Capture by Reference

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<double> coll = {3.14, 2.96, 2.87};

    // process average value of all elements
    double sum = 0.0;
    std::for_each(coll.begin(),
                  coll.end(),
                  [&sum](double d) // [&] would catch all by reference
                  {
                      sum += d;
                  });

    std::cout << "average: " << sum / coll.size() << '\n';
}
