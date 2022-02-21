---
layout: default
title: TDD
nav_order: 2
description: 'What is TDD?'
parent: Test
---

Test Driven Development
{: .fs-9}

What is TDD?
{: .fs-6 .fw-300  }

<a style="color:white" href="#red">Red</a>
{: .label .label-red } 

<a style="color:white" href="#green">Green</a>
{: .label .label-green  } 

<a style="color:white" href="#purple">Purple</a>
{: .label .label-purple  } 

In general terms, Test-Drive Development is based on the Red, Green, Purple cycle. First, in red you must write a test that will fail, in green you must make the code work and in purple you must remove redundancy.

<a href="{{ site.baseurl }}/assets/images/test/tdd.png" data-toggle="lightbox">
    <img src="{{ site.baseurl }}/assets/images/test/tdd.png" class="img-fluid" />
</a>

###### From [AUDY (2012)](#ref1)

That is:

{: #red}
- <p style="color:red">1. Add a test</p>

To write a test, the developer needs to understand the specifications and requirements of the functionality. The developer can do this through use cases that cover requirements and conditional exceptions.

This is the difference between test driven development and writing unit tests after the code is developed. It makes the developer focus on requirements before code, which is a subtle but important difference.

- <p style="color:red">2. Run all tests and see if any of them fail</p>

This step validates that all tests are working correctly and that the new test does not have any errors, without requiring any new code. It can be considered that this step then tests the test itself: it regulates the possibility of a new test passing.

The retest should then fail for the expected reason: the functionality was not developed. This builds confidence (on the other hand doesn't exactly guarantee it) that you're testing the right thing, and that the test will only pass the intended cases.

{: #green}
- <p style="color:green">3. Write code</p>  

The next step is to write code that will cause the test to pass, use falsification and duplication. New code written up to this point may not be perfect and may, for example, pass the test in an inelegant way. This is acceptable because later it will be improved.

The important thing is that the code written must be built only to pass the test; no functionality (let alone untested) should be predicted or allowed at any point

- <p style="color:green">4. Run automated tests and see them run successfully</p> 

If all tests now pass, the programmer can be confident that the code meets all the tested requirements. This is a good point that starts the final step of the TDD cycle.

{: #purple}
- <p style="color:purple">5. Refactor</p> 

At this point the code can be cleaned up as needed. By re-running the tests, the developer can be confident that the refactoring is not a harmful process to any existing functionality. A relevant concept at this time is that of triangulation, which consists of removing falsification and duplication of code, considered an important aspect of software design. 

- <p style="color:black">6. Repeat all</p> 

Starting with another test, the cycle is then repeated, pushing the functionality forward. The size of the steps should be small - as little as 1 to 10 text edits between each test run. If new code does not quickly satisfy a new test, or other tests fail unexpectedly, the programmer should undo or roll back the changes rather than using excessive debugging. Continuous integration helps provide reversible points.

## Benefits

TDD is has a quick feedback. If you did the function but didn't get a positive test result, it can be modified right away. Because you have to focus specific development problems it create cleaner and simpler code that is also easy to refactor. Bugs are easier to fix and also increase the productivity.

## References

[1] AUDY Jorge. (2012) TDD – Test Driven Development. Available at: <https://jorgeaudy.com/2012/07/12/tdd-test-driven-development/>. Accessed: February 21, 2022.
{: #ref1}