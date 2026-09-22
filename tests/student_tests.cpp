#include "packet_analysis.hpp"

#include <cstdlib>
#include <iostream>
#include <string_view>

namespace {

void require(bool condition, std::string_view message) {
    if (!condition) {
        std::cerr << "FAILED: " << message << '\n';
        std::exit(1);
    }
}

}  // namespace

void run_student_tests() {
    // TODO: Add at least four focused tests as described in the assignment.
    require(true, "student test placeholder");
}
