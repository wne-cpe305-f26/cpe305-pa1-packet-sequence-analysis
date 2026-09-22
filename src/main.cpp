#include "packet_analysis.hpp"

#include <iostream>

int main() {
    Node fourth{{5, 120}, nullptr};
    Node third{{3, 90}, &fourth};
    Node second{{8, 120}, &third};
    Node first{{3, 40}, &second};

    const std::vector<Packet> selected =
        collect_packets_in_range(&first, 90, 120);

    std::cout << "Packets from 90 through 120 bytes:\n";
    for (const Packet& packet : selected) {
        std::cout << "source=" << packet.source
                  << ", bytes=" << packet.bytes << '\n';
    }

    const SourceRun run = longest_source_run(&first);
    if (run.first != nullptr) {
        std::cout << "Longest source run begins with source "
                  << run.first->value.source
                  << " and has length " << run.length << '\n';
    }
}
