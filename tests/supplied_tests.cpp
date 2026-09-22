#include "packet_analysis.hpp"

#include <cstdlib>
#include <iostream>
#include <string_view>
#include <vector>

namespace {

void require(bool condition, std::string_view message) {
    if (!condition) {
        std::cerr << "FAILED: " << message << '\n';
        std::exit(1);
    }
}

void test_collects_matching_packets_in_order() {
    Node fourth{{5, 120}, nullptr};
    Node third{{3, 90}, &fourth};
    Node second{{8, 120}, &third};
    Node first{{3, 40}, &second};

    const std::vector<Packet> actual =
        collect_packets_in_range(&first, 90, 120);
    const std::vector<Packet> expected{{8, 120}, {3, 90}, {5, 120}};

    require(actual == expected, "range collection preserves matching order");
}

void test_collects_empty_and_invalid_ranges() {
    Node only{{4, 90}, nullptr};

    require(collect_packets_in_range(nullptr, 0, 100).empty(),
            "empty list produces an empty collection");
    require(collect_packets_in_range(&only, 100, 90).empty(),
            "reversed range produces an empty collection");
}

void test_longest_source_run() {
    Node sixth{{3, 10}, nullptr};
    Node fifth{{8, 60}, &sixth};
    Node fourth{{8, 70}, &fifth};
    Node third{{8, 120}, &fourth};
    Node second{{3, 90}, &third};
    Node first{{3, 40}, &second};

    const SourceRun actual = longest_source_run(&first);

    require(actual.first == &third, "longest run starts at the first source-8 node");
    require(actual.length == 3, "longest run has length three");
}

void test_longest_source_run_prefers_first_tie() {
    Node fourth{{8, 40}, nullptr};
    Node third{{8, 30}, &fourth};
    Node second{{3, 20}, &third};
    Node first{{3, 10}, &second};

    const SourceRun actual = longest_source_run(&first);

    require(actual.first == &first, "equal longest runs prefer the first run");
    require(actual.length == 2, "tied longest run length is correct");
    require(longest_source_run(nullptr).first == nullptr,
            "empty list has no first run node");
    require(longest_source_run(nullptr).length == 0,
            "empty list has run length zero");
}

}  // namespace

void run_supplied_tests() {
    test_collects_matching_packets_in_order();
    test_collects_empty_and_invalid_ranges();
    test_longest_source_run();
    test_longest_source_run_prefers_first_tie();
}
