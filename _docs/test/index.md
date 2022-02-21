---
layout: default
title: Test 
nav_order: 3
description: 'Why test your app?'
has_children: true
permalink: /test 
---

Test
{: .fs-9}

Why test your app?
{: .fs-6 .fw-300  }

<a style="color:white" href="#bug">Bug, Defect, Error, Failure</a>
{: .label .label-red } 

<a style="color:white" href="#whitebox">White Box</a>
{: .label .label-purple  } 

<a style="color:white" href="#blackbox">Black Box</a>
{: .label .label-purple  } 

<a style="color:white" href="#graybox">Gray Box</a>
{: .label .label-purple  }

{: #bug}
When Software fails, does not work properly, it can lead to many problems such as financial losses, loss of reputation, risk to people's physical integrity, contractual fines. These failures occur because all software development artifacts, from specification and requirements to general documentation, are written by people, and people are prone to making mistakes, regardless of their experience and qualifications.

We can define errors as a human action that produces an incorrect result. They are often committed by programmers, causing defects. Defects or Bugs are manifestations of an error in the software and if executed, the defect can cause a failure. Failure is the undesirable difference between the observed and the expected, the result of the mistake made, the defect found [[1]](#ref1).  

## White Box 
{: #whitebox}

White Box tests are those performed to analyze web applications, where the server configuration and the source code itself are openly analyzed in search of security flaws that could compromise the service [[2]](#ref2). 

Basically, White Box is testing the internal coding and infrastructure of a software solution. It mainly focuses on strengthening safeguard, the flow of inputs and outputs through the application, and improving design and usability. [[3]](#ref3). 

All customer information about the network, servers, database and systems that are included in the test scope so more comprehensive tests can be performed.

## Black Box
{: #blackbox}

It is the closest type of analysis to an external attack, as no information from the customer is provided to the test analyst. That's because it's being tested from an external or end-user perspective. That is the opposite of white box testing because white box is based on the internal operation of an application and is about internal testing [[3]](#ref3). 

The name 'black box' in 'Black Box Testing' symbolizes that we cannot see the inner workings of the software. Therefore, we can only test the end-user experience. Therefore, any type of information for carrying out a Black Box test is acquired through specific hacking techniques on the available services of the target, thus identifying vulnerabilities and possible damage caused by a malicious attack [[2]](#ref2).

## Gray Box
{: #graybox}

This type of analysis can be considered a mix of the previous ones, as the test analyst receives some information from the client, such as: data from the network infrastructure or access to a certain web service. Gray box testing is when the tester has a partial understanding of the internal structure of the system under test. Gray box testing is a process for debugging software applications by making an input through the front end and verifying the data on the back end [[2]](#ref2) [[3]](#ref3).

A good example of Gray Box tests are those aimed at analyzing possible security flaws in an application coming through an accredited user, such as access permission levels and unauthorized changes [[2]](#ref2).

## White Box vs Gray Box

| Teste     | Benefits | Disadvantages |
| --------- | ---------- | ------------ |
| White Box | Code optimization when finding hidden errors.<br>We can also easily automate test cases for the white box.<br>Testing is more thorough because we usually check all code paths.<br> Testing can start at the beginning of the project, even if the GUI is not availabl | White box testing can be complex and expensive.<br>Developers who generally run test cases for white boxes hate it. Developers therefore do not test the white box in detail, which can lead to production errors.<br>In addition, white box testing requires professional tools and in-depth knowledge of programming and implementing.<br>White box testing is time consuming, takes time to test larger applications |
| Gray Box | Gray box testing is done from the end user's perspective, not the designer's or engineer's perspective.<br>It offers the benefits of black box and white box testing together.<br>They will be based on functional specifications, user stories and architecture diagrams, allowing verification of original requirements.<br>Testing will be unbiased as there will be more discussions between the software testers' thoughts and the designer's or engineer's thoughts. | Gray box testing can also take a long time to test all input paths, and sometimes this is unrealistic.<br>This generally results in lower test coverage than black and white box tests separately.<br>It may not be suitable for testing some types of functionality. |

[[2]](#ref2).

## Why do software testing?

Software testing is very important in ensuring system quality control. He must ensure that the system meets all the requirements as the customer requested [[2]](#ref2).

The inputs and outputs of all software must be reliable. For this, different types of tests are needed to simulate certain behavior of the application, generally before its release from the production environment. Finally, tests are tools that companies use to minimize financial costs and prevent business reputation from decreasing [[2]](#ref2).

## References

[1] JORDAN, Melanie. (2018) Fundamentos Do Teste De Software - Falha, Defeito E Erro. *BACKEFRONT*  Available at: <https://backefront.com.br/fundamentos-teste-software/#:~:text=Erro%3A%20%C3%A9%20uma%20a%C3%A7%C3%A3o%20humana,o%20resultado%20do%20erro%20cometido.>. Accessed: February 20, 2022.
{: #ref1}

[2] RODRIGUES, Caroline (2019) Teste de software: entenda as diferenças entre Black, Gray e White Box. *BOAVISTA*. Available at: <https://boavistatecnologia.com.br/blog/teste-de-softwares/>. Accessed: February 20, 2022.
{: #ref2}

[3] (2016) Tipos de Pentest?. *AUZAC*. Available at: <https://www.auzac.com.br/testes-de-invasao/tipos-de-pentest/>. Accessed: February 20, 2022.
{: #ref4}