# CPE305 Programming Assignment 01

Implement two iterative traversals over a supplied singly linked list of packet records.

The complete assignment specification is distributed through Kodiak and links to this starter repository.

## Required work

Implement both functions in `src/packet_analysis.cpp` and add at least four focused tests to `tests/student_tests.cpp`.

Do not change the required declarations or public data structures in `include/packet_analysis.hpp`.

## Build and test

Run commands from the repository root:

```sh
make
./bin/packet_analysis
make test
make clean
```

The supplied `Makefile` requires a C++20 `g++` or `clang++` compiler. To use Clang explicitly, run `make CXX=clang++`.

## Optional Codespaces environment

GitHub Codespaces is optional. Select **Code**, then **Codespaces**, then **Create codespace on main**. The container builds the tests after creation. Running `make test` will fail until both functions are implemented.

You may instead clone or download the repository and work locally on macOS or Linux.

## Submission archive

Create the ZIP only after your implementation and tests pass:

```sh
make clean
zip -r submission.zip . -x 'submission.zip' '.git/*' 'bin/*' 'build/*' '.vscode/*'
```

Open the ZIP and confirm that it contains the complete source tree before uploading it through Kodiak.
