---
layout: default
title: Backtracking
nav_order: 3
description: 'Backtracking algorithms'
parent: Design
grand_parent: Algorithm
---


# Backtracking 
{: #analysis}

What is?
{: .fs-6 .fw-300  }

Backtracking is an algorithmic technique used for solving problems recursively by building a solution incrementally, one piece at a time, and removing solutions that fail to satisfy the problem constraints at any point. It is particularly useful for problems that involve exploring combinatorial spaces where potential solutions can be represented as a tree of possibilities.

Key Concepts of Backtracking:
{: .fs-6 .fw-300  }

### Incremental Construction:

Backtracking attempts to construct a solution incrementally. It explores potential solutions step by step. At each step, it tries out all possible options for the next part of the solution.

### Decision Tree:

The potential solutions can be visualized as a tree, where each node represents a decision point. Branches represent the choices made, leading to further nodes until either a solution is found or a dead end is reached.

### Backtrack on Failure:

If a choice leads to a partial solution that cannot lead to a complete, valid solution, the algorithm backtracks to the previous decision point. It undoes the last choice and tries a different option. This process continues until a valid solution is found or all options have been exhausted.

Steps in a Backtracking Algorithm:
{: .fs-6 .fw-300  }

- Choose: Select a potential option for the next step.
- Check: Determine if this option leads towards a valid solution.
  - If yes, recurse (move forward with this choice).
  - If no, backtrack (undo the choice and try a different one).
- Repeat until a complete solution is found or all possibilities are checked.
- 
When to Use Backtracking:
{: .fs-6 .fw-300  }

Backtracking is effective for problems where you need to explore multiple potential solutions and: The search space is large and needs pruning. All possible solutions need to be considered, or you need the first valid solution. The problem can be formulated as a recursive exploration of decisions.
