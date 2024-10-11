---
layout: default
title: Recurrence
nav_order: 1
description: 'Solving Recurrence'
parent: Divide and Conquer
---

Solving recurrences
{: .fs-9}

We’ll explore several mathematical tools for solving recurrences that is, for obtaining asymptotic bounds on their solutions. We want simple-to-use tools that can handle the most commonly occurring situations. But we also want general tools that work, perhaps with a little more effort, for less common cases.  

## Substitution method

In the substitution method, you guess the form of a bound and then use mathematical induction to prove your guess correct and solve for constants. This method is perhaps the most robust method for solving recurrences, but it also requires you to make a good guess and to produce an inductive proof. 
The substitution method comprises two steps:

1. Guess the form of the solution using symbolic constants.
2. Use mathematical induction to show that the solution works, and ûnd the constants.

To apply the inductive hypothesis, you substitute the guessed solution for the function on smaller values hence the name substitution method. This method is powerful, but you must guess the form of the answer. Although generating a good guess might seem difûcult, a little practice can quickly improve your intuition. 

## The recursion-tree method 

The recursion-tree method models the recurrence as a tree whose nodes represent the costs incurred at various levels of the recursion. To solve the recurrence, you determine the costs at each level and add them up. Even if you don’t use this method to formally prove a bound, it can be helpful in guessing the form of the bound for use in the substitution method.

In a recursion tree, each node represents the cost of a single subproblem somewhere in the set of recursive function invocations. You typically sum the costs within each level of the tree to obtain the per-level costs, and then you sum all the per-level costs to determine the total cost of all levels of the recursion. Sometimes, however, adding up the total cost takes more creativity. 

A recursion tree is best used to generate intuition for a good guess, which you can then verify by the substitution method. If you are meticulous when drawing out a recursion tree and summing the costs, however, you can use a recursion tree as a direct proof of a solution to a recurrence. But if you use it only to generate a good guess, you can often tolerate a small amount of sloppiness which can simplify the math. When you verify your guess with the substitution method later on, your math should be precise. 

## The master 

The master method is the easiest method, when it applies. It provides bounds for recurrences of the form
T(n) = aT(n/b) + f(n) ; where a > 0 and b > 1 are constants and f(n) is a given driving function.

This type of recurrence tends to arise more frequently in the study of algorithms than any other. It characterizes a divide-and-conquer algorithm that creates a subproblems, each of which is 1=b times the size of the original problem, using f(n) time for the divide and combine steps. 

To apply the master method, you need to memorize three cases, but once you do, you can easily determine asymptotic bounds on running times for many divide-and-conquer algorithms.

1. If there exists a constant **ε > 0** such that `f(n) = O(n^(log_b a - ε))`, then:
2. If there exists a constant **k ≥ 0** such that `f(n) = Θ(n^log_b a * log^k n)`, then:
3. If there exists a constant **ε > 0** such that `f(n) = Ω(n^log_b a + ε)`, and if `f(n)` additionally satisfies the regularity condition `a f(n/b) ≤ c f(n)` for some constant **c < 1** and all sufficiently large **n**, then:

