#ifndef PACKET_ANALYSIS_HPP
#define PACKET_ANALYSIS_HPP

#include <cstddef>
#include <vector>

struct Packet {
    int source;
    int bytes;

    bool operator==(const Packet&) const = default;
};

struct Node {
    Packet value;
    Node* next;
};

struct SourceRun {
    const Node* first;
    std::size_t length;
};

std::vector<Packet> collect_packets_in_range(
    const Node* head,
    int minimum_bytes,
    int maximum_bytes);

SourceRun longest_source_run(const Node* head);

#endif
