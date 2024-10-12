---
layout: default
title: Dynamic
nav_order: 3
description: 'Dynamic Programming'
parent: Design
grand_parent: Algorithm
---

Dynamic Programming 
{: #analysis}

What is?
{: .fs-6 .fw-300  }

Dynamic programming, like the divide-and-conquer method, solves problems by combining the solutions to subproblems

Dynamic programming typically applies to optimization problems. Such problems can have many possible solutions. Each solution has a value, and you want to ûnd a solution with the optimal (minimum or maximum) value. We call such a solution an optimal solution to the problem, as opposed to the optimal solution, since there may be several solutions that achieve the optimal value.

To develop a dynamic-programming algorithm, follow a sequence of four steps:

1. Characterize the structure of an optimal solution. You will ûnd yourself following a common pattern in discovering optimal substructure:
    1. You show that a solution to the problem consists of making a choice, such as choosing an initial cut in a rod or choosing an index at which to split the matrix chain. Making this choice leaves one or more subproblems to be solved.
    2. You suppose that for a given problem, you are given the choice that leads to an optimal solution. You do not concern yourself yet with how to determine this choice. You just assume that it has been given to you.
    3. Given this choice, you determine which subproblems ensue and how to best characterize the resulting space of subproblems.
    4. You show that the solutions to the subproblems used within an optimal solution to the problem must themselves be optimal by using a "cut-and-paste" technique. You do so by supposing that each of the subproblem solutions is not optimal and then deriving a contradiction. In particular, by "cutting out" the nonoptimal solution to each subproblem and "pasting in" the optimal one, youshow that you can get a better solution to the original problem, thus contradicting your supposition that you already had an optimal solution. If an optimal solution gives rise to more than one subproblem, they are typically so similar that you can modify the cut-and-paste argument for one to apply to the others with little effort. 
3. Recursively deûne the value of an optimal solution.
4. Compute the value of an optimal solution, typically in a bottom-up fashion.
5. Construct an optimal solution from computed information
   
