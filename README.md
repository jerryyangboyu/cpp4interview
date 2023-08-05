# Algos4cpp Introduction to Algorithm and Data Structures
This repository contains implementation of basic data structures and common algorithm. For practise purpose, typical
LeetCode problems are also included to demostrate the use of algorithm. Each solution is collected through 4 different category:
data, math, sort, search, graph and string

- data: common data structures including List, Queue, Priority Queue, Stack, etc.
- math: essential procedure algorithm for CS. e.g. Gaussian Elimination, Matrix Calculation, Logic Induction and Evaluation, etc.
- sort: common sort techniques, including array sort, balanced tree sort, 3-way-sort, etc.
- graph: typical graph algorithm, including minimum spanning tree, the shortest path, etc.
- string: typical string algorithm and data structures, including tries, strings sort, etc.

## Including The Implementation in Projects
The project is written in static library. You may include the source code and header file into the project. The `headers` folder
contains essential information of function and class declaration *under namespace `algos4j`*. The `src` folder contains
implementation of head file, where source code is categorized by above category.

## Tests, Efficiency and Correctness of Implementation
For each LeetCode problem, a solution ranking, time and space used should be specified. For common algorithm, the origin of code
should be specified and approximate theoretical space and time usage should be included.

## Progress Check
Category | Algo Name               | Status     | Test Results | Space Usage     | Time Usage        | Start Date| Reference
---------|-------------------------|------------|--------------|-----------------|-------------------|-----------|----------
Graph    | Union-Found             | `on-going` | N/A          | ```O(N)```      | ```O(lg(N))```    | 2022/5/16 | *Algos4*
LinkedList| Add Two Number         | `finished` | All Passed   | ```O(1)```      | ```O(N)```        | 2022/5/17 | https://leetcode.cn/problems/add-two-numbers/


## License
GPLv3, for more information see [here](https://choosealicense.com/licenses/gpl-3.0/#)
