---
layout: default
title: Physical
nav_order: 1
description: 'Physical Design'
grand_parent: Database
parent: Project
---

Physical
{: .fs-9}

Physical Design
{: .fs-6 .fw-300  }
In a physical project, you are not only looking to store data properly, but also to obtain good performance. For the development of a good physical project, it is necessary to have a good knowledge about the operations performed on the database and the applications that will perform these operations. Such as the most performed queries, frequency of queries, maximum expected response times, among others [[1]](#ref1).

Some important analyzes to be carried out for the construction of a physical project are the following:

- Queries and transactions performed in the database - Aspects related to queries must be known, such as attributes that will be used for filtering, attributes that will be retrieved, selection conditions (equality, inequality or range), attributes used to make joins tables.
- Frequency of calling queries – The frequency with which queries are used is an important point to be analyzed, as this information can
assist in the process of prioritizing queries to be improved.
- Time in which the query must be performed - It is important to know if any query has performance restrictions, since, in some cases, a certain
business rule may require a query to run in a maximum time.
- Frequency at which insertions and/or modifications are performed - The frequency at which insertions and/or modifications are performed is an important aspect to be analyzed, since, in the case of a table receiving more insertions and/or modifications than queries , the presence of too many indexes on attributes can be detrimental to performance.

## Normalization

Normalization is a set of rules that provides a means to remove or control redundancy (repeated data) from the database, so that you can
get some performance improvements, such as [[1]](#ref1):

- Updating data in normalized tables is faster than in non-normalized tables;
- Properly normalized tables result in little or no duplicate data, so there is less data to update;
- Normalized tables tend to be smaller, and thus, take up less disk space;
- Normalized tables make fewer operations necessary for the
carrying out consultations.

Within the normalization process, there are six normal forms. However, the main ones are the first three because they are more focused on controlling the redundancy and consistency of the stored data [[1]](#ref1):
- **First normal form (1FN)**- According to first normal form (1FN), only atomic values ​​are allowed in a relation. Therefore, there should be no need for tuples with repeated values ​​or attributes with more than one value to be stored in the same tuple;
- **Second normal form (2FN)**- To achieve second normal form (2FN), the relation must first be in first normal form (1FN). Also, to be considered in second normal form (2NF), all attributes of the relation that are not primary keys must depend solely on the primary key of the relation. In case of composite primary key, attributes that are not primary key must depend on all attributes of the primary key, not just part of them.;
- **Third normal form (3FN)**- To be in third normal form (3FN), the relation must be in second normal form (2FN). Also, all attributes that are not keys must be functionally independent of other attributes that are not keys.

## References

[1]  MARTINS, B; SILVA, M. Aprimoramento de desempenho de banco de dados: um estudo de caso de um Sistema Tutor Inteligente. Faculdade UnB Gama, Universidade de Brasília. Brasília p. 175. 2019.
{: #ref1}