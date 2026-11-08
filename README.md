# Code-Template

A comprehensive collection of **115+ competitive programming data structures and algorithms** implemented in C++. This repository serves as a quick reference for common algorithmic problems and techniques used in competitive programming.

## 📋 Table of Contents

- [Setup & Build](#setup--build)
- [Algorithm Categories](#algorithm-categories)
- [Quick Reference](#quick-reference)

## Setup & Build

### Prerequisites

- **g++-14** or later
- **macOS 10.x+** (configured for C++23)

### Configuration

The project is configured for VS Code with automatic build settings:

- **Compiler**: g++-14
- **Standard**: C++23
- **Debug Flag**: `-DDEBUG`
- **macOS Deployment Target**: 27.0

### Building

#### Using VS Code
1. Open a `.cpp` file
2. Press `Cmd + Shift + B` to run the default build task
3. Or click the Run button (play icon) to compile and execute

#### Using Terminal
```bash
export MACOSX_DEPLOYMENT_TARGET=27.0
g++-14 -DDEBUG -std=c++23 "file.cpp" -o "output"
./output
```

## Algorithm Categories

### 📊 Data Structures

#### Trees & Graph Structures
- **Trie.cpp** - Prefix tree for string matching
- **SCC.cpp** - Strongly Connected Components
- **BCC.cpp** - Biconnected Components
- **TreeDp.cpp** - Tree Dynamic Programming
- **CenterOfTree.cpp** - Find tree center(s)
- **Lowest_common_ancestor.cpp** - LCA queries
- **HLD-anudeep.cpp** - Heavy-Light Decomposition

#### Segment Trees
- **SegmentTree(LazyProp).cpp** - Segment Tree with lazy propagation
- **SegmentTree-KeepMinUpdate-MinQuery.cpp** - Min query segment tree
- **SegmentTreePersistent.cpp** - Persistent segment tree
- **SegmentTreePersistent-shared-ptr.cpp** - Persistent segment tree (smart pointers)
- **2D - Segment Tree.cpp** - 2D segment tree
- **2D - Segment Tree with lazyProp.cpp** - 2D segment tree with lazy propagation

#### Binary Indexed Tree (Fenwick Tree)
- **BIT(SUM).cpp** - Basic BIT for range sum queries
- **BIT(SUM2).cpp** - Extended BIT implementation
- **2D-MIN-BIT.cpp** - 2D BIT for minimum queries

#### Union-Find / Disjoint Set
- **DisjointSet.cpp** - Basic disjoint set with path compression
- **DisjointSet-Struct.cpp** - Disjoint set as a struct

#### Other Data Structures
- **PersistentQueue.cpp** - Persistent queue implementation
- **2D - Array Matching.cpp** - 2D array pattern matching
- **deque.cpp** - Deque operations and usage
- **map.cpp** - Map data structure examples

### 🔤 String Algorithms

- **KMP.cpp** - Knuth-Morris-Pratt string matching
- **KMP+failure.cpp** - KMP with failure function
- **Ahocorasick.cpp** - Aho-Corasick algorithm
- **Ahocorasick II.cpp** - Alternative Aho-Corasick implementation
- **Ahocorasick_updated.cpp** - Updated Aho-Corasick with fixed naming
- **Rolling-Hash.cpp** - Polynomial rolling hash
- **Hashing.cpp** - General hashing techniques
- **Manacher_s_Longest_palindromic_substring.cpp** - Find longest palindromic substring
- **Suffix_Array_nlogn.cpp** - Suffix array O(n log n)
- **Suffix_Array_nlogn(n)^2.cpp** - Alternative suffix array
- **SuffixArrayDC3.cpp** - Suffix array DC3 algorithm
- **Suffix_Automaton.cpp** - Suffix automaton
- **Suffix_Automata_Test.cpp** - Suffix automaton tests
- **Suffix_Automata_Test(v2.0).cpp** - Suffix automaton v2
- **longest_common_substring.cpp** - LCS implementation
- **longest_common_subsequence.cpp** - LCS DP approach
- **string.cpp** - String utilities
- **string_operation.cpp** - String operations
- **string_stream.cpp** - String stream usage

### 🔢 Number Theory & Math

#### Modular Arithmetic
- **Chinese_Remainder_Theorem.cpp** - CRT for modular equations
- **Extended Euclid.cpp** - Extended GCD algorithm
- **Phi+BurnsideLemma.cpp** - Euler's totient and Burnside's lemma
- **bitwise_sieve.cpp** - Efficient prime sieve using bitwise operations
- **Segment_Seive.cpp** - Segmented sieve for large ranges

#### Matrix Operations
- **Matrix_Expo.cpp** - Matrix exponentiation
- **Matrix_Expov2.0.cpp** - Matrix exponentiation v2.0
- **Gauss(partial).cpp** - Gaussian elimination (partial)
- **Gauss(partial_new).cpp** - Gaussian elimination (new)
- **Gauss(mod-2).cpp** - Gaussian elimination mod 2
- **Gauss(mod-2)-with-rank.cpp** - Gaussian elimination mod 2 with rank
- **Gauss(mod-k)-with-rank.cpp** - Gaussian elimination mod k with rank

#### Miscellaneous Math
- **BigInteger.cpp** - Big integer implementation
- **Fraction.cpp** - Fraction arithmetic
- **baseConversion.cpp** - Number base conversion
- **all_divisor.cpp** - Find all divisors
- **CustomHash.cpp** - Custom hash function

### 🌐 Graph Algorithms

#### Shortest Path
- **Dijkstra.cpp** - Dijkstra's algorithm
- **Bellman_Fords.cpp** - Bellman-Ford algorithm
- **MaxFlow_MinCut_Dinic_s.cpp** - Dinic's max flow algorithm
- **MaxFlow_MinCut_Dinic_s_Mine.cpp** - Alternative Dinic's implementation

#### Maximum Flow / Minimum Cost Flow
- **Dinics-Maxflow.cpp** - Dinic's max flow
- **Maxflow_Mincost.cpp** - Min-cost max-flow
- **MincostMaxFlow - SPFA.cpp** - Min-cost max-flow using SPFA
- **Maxflow_Mincut.cpp** - Max-flow min-cut theorem
- **MinCut_MaxFlow v2.0.cpp** - Max-flow min-cut v2.0

#### Matching Algorithms
- **BPM.cpp** - Bipartite matching
- **BPM-(Hopcroft-Karp).cpp** - Hopcroft-Karp bipartite matching
- **Hoptcroft-Karp.cpp** - Hopcroft-Karp implementation
- **BlossomAlgorithm.cpp** - Blossom algorithm for general matching
- **Hungarian(int).cpp** - Hungarian algorithm (integer)
- **Hungarian(Double).cpp** - Hungarian algorithm (double)
- **Stable-Marriage-Problem.cpp** - Stable marriage problem

#### Articulation & Bridges
- **Articulation_point.cpp** - Find articulation points (cut vertices)
- **Articulation_bridge.cpp** - Find bridges in a graph

#### Minimum Spanning Tree
- **MST_krushkel.cpp** - Kruskal's MST algorithm
- **MST-Directed.cpp** - MST for directed graphs

#### Other Graph Algorithms
- **2-SAT.cpp** - 2-SAT solver

### 🎯 Dynamic Programming

- **Longest_Increasing_Subsequence.cpp** - LIS using DP
- **lis_n^2.cpp** - LIS O(n²) approach
- **KnuthTrick.cpp** - Knuth optimization for DP
- **ConvexHullTrick.cpp** - Convex hull trick optimization
- **Mo_s_Algo(Sqrt Decomposition).cpp** - Mo's algorithm with sqrt decomposition
- **MaxMinSlidingWindow.cpp** - Min/max in sliding window

### 📐 Computational Geometry

- **GeometryTemplate2D.cpp** - 2D geometry utilities
- **GeometryTemplate2D(Farsid_BUET).cpp** - 2D geometry (Farsid variant)
- **GeometryTemplate2D(Nafis_JU_IIT).cpp** - 2D geometry (Nafis variant)
- **GeometryTemplate2D(integer).cpp** - 2D geometry with integer coordinates
- **GeometryTemplate3D.cpp** - 3D geometry utilities
- **ConvexHull.cpp** - Convex hull algorithm
- **ConvexHull_Final.cpp** - Convex hull (final version)
- **ClosestPair.cpp** - Closest pair of points
- **line_intersection.cpp** - Line intersection detection
- **line_intersection(1).cpp** - Alternative line intersection
- **Pick_sTheorem.cpp** - Pick's theorem for polygon area

### 🔄 Fourier & Number-Theoretic Transforms

- **FFT(without modulo).cpp** - Fast Fourier Transform
- **FFT(without modulo+complexStructure).cpp** - FFT with complex numbers
- **FFT(with modulo).cpp** - FFT with modular arithmetic (NTT)
- **testfft.cpp** - FFT tests
- **testfft_new.cpp** - FFT tests (new)
- **testfft(ntt).cpp** - NTT tests
- **testfft_old.cpp** - FFT tests (old)

### 🛠️ Utilities & Helper Functions

- **precode.cpp** - Common prewritten code template
- **precode (nafis).cpp** - Nafis's precode template
- **pre_code (shakil).cpp** - Shakil's precode template
- **TopcoderPrecode.cpp** - Topcoder prewritten code
- **Faster_IO.cpp** - Optimized I/O operations
- **merge_sort.cpp** - Merge sort implementation
- **backtracking_introduction_permutation.cpp** - Backtracking for permutations
- **construct_graph_from_pre_inoder.cpp** - Reconstruct tree from traversals
- **sqrtDecomposition.cpp** - Sqrt decomposition technique
- **Histogram.cpp** - Largest rectangle in histogram
- **Kth Minimum Element EX.cpp** - Kth smallest element

## Quick Reference

### Common Build Commands

```bash
# Build with debugging
g++-14 -DDEBUG -std=c++23 "file.cpp" -o "output"

# Build and run
export MACOSX_DEPLOYMENT_TARGET=27.0
g++-14 -DDEBUG -std=c++23 "file.cpp" -o "output" && ./output
```

### VS Code Shortcuts

- **Build**: `Cmd + Shift + B`
- **Run**: Click play icon or use Code Runner
- **Debug**: Press `F5`

## Project Structure

```
Code-Template/
├── .vscode/
│   ├── settings.json          # Global VS Code settings
│   ├── tasks.json             # Build tasks
│   ├── launch.json            # Debug configuration
│   └── c_cpp_properties.json  # C++ intellisense config
├── C++/                       # 115+ algorithm implementations
└── README.md                  # This file
```

## Notes

- All code is optimized for competitive programming
- Some implementations may have multiple variants (e.g., different geometry templates)
- Code uses C++23 standard for modern features
- Includes debug mode with `MACOSX_DEPLOYMENT_TARGET=27.0` for macOS compatibility

## License

This is a personal collection of competitive programming templates. Feel free to use for learning and contests.

