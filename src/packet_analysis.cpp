#include "packet_analysis.hpp"

std::vector<Packet> collect_packets_in_range(
    const Node* head,
    int minimum_bytes,
    int maximum_bytes) {
    // TODO: Return matching packets in their original order.
    static_cast<void>(head);
    static_cast<void>(minimum_bytes);
    static_cast<void>(maximum_bytes);
    return {};
}

SourceRun longest_source_run(const Node* head) {
    // TODO: Return the first longest contiguous run of one source.
    static_cast<void>(head);
    return {nullptr, 0};
}
