---
layout: default
title: Tuning
nav_order: 1
description: 'What is Tuning?'
grand_parent: Database
parent: Technique
---

Tuning
{: .fs-9}

What is Tuning?
{: .fs-6 .fw-300  }

In order to guarantee the proper functioning of this technology (DBMS), a technique known in the Database area as tuning can be applied – an activity that makes the DBMS work with greater performance in its internal processing, achieving better transfer rates. to meet the diverse requests of its different users. For this, adjustments are usually necessary, for example, changes in the way the software that will use it was built, in the existing data structures in the DBMS, in its operating parameters and in the more coherent configuration of the Operating System and even the hardware at the same time. which the DBMS will be working [[1]](#ref1).

The importance of applying performance improvement techniques in the database is strongly shown when considering some aspects, such as helping the user experience of using the system – in which the performance improvement techniques are applied – , as well as reducing the operating cost to keep the system running. When performance optimization techniques are applied, aiming to achieve modeling and implementations that correctly address the problem, time and money can be saved: time, since the cases where there is rework are reduced, the occurrences of bug fixes among other computer problems; money, once the processing power demanded falls, the costs with labor and/or specialized support are reduced, among others [[1]](#ref1).

In addition, a DBMS that makes proper use of the resources offered to it – which can be obtained through analysis and improvements –, better presents some important characteristics, such as scalability, performance and high availability. From an end-user perspective, the impacts of a performance issue vary, in some cases being limited to just a brief delay in the end-user experience. However, it is also possible for the application to become completely or partially inaccessible. At the same time, numerous studies demonstrate the relationship between response time and end-user satisfaction, and while response time is just one of many factors that affect user satisfaction, it is often of great importance [[1]](#ref1).

## Otimizando

To explain about optimization, we will subdivide it into three main parts:
- Schema – Improvements related to the physical implementation of the database.
- Queries – Optimizations related to the main queries performed in the database.
- Indexing – Adjustments related to the use of strategic and coherent indexes for the main queries that are performed on the database.

### Schema
#### Denormalization

Data normalization is considered a good practice, yet, in some cases, data denormalization can show positive results in the database. In a denormalized relationship, certain types of queries can be performed much more quickly. In a context in which the data of a relation are repeatedly consulted together with another relation, the union of these two relations, despite bringing problems inherent to denormalization, can allow queries that previously needed JOINS to be executed in a trivial way, thus being more fast [[1]](#ref1).

The advantage of storing the data that will be recovered together, in a single table, is the reduction of unnecessary accesses to the disk. In cases where the retrieved data does not fit in memory, this is especially beneficial to the performance of the database in question [[1]](#ref1).

### Queries

The analysis of the elaborated queries that arrive for the DBMS to carry out is a way of optimizing the bank. Improving the queries performed is essential for optimization. Since they are the ones that define how the database should be optimized, they are the ones that use the indexes and relationships involved in retrieving the desired data. The subsections contained within this section present examples of some common errors and what can be done in this scope of the physical project [[1]]](#ref1).

#### Requesting Data Not Required

Some queries end up requesting data that are not really needed, and this causes unnecessary hardware resources to be consumed, including to perform them [[1]](#ref1). These are some of the most common errors encountered in queries:

- Request more tuples than necessary – This error refers to the action of requesting too many tuples of data, when only an amount N is needed.
- Request all columns in a table join – This error refers to the action of requesting all columns in a table join, when in fact only specific columns are needed.
- Request all columns - As seen in the previous item, requesting more data than necessary is not recommended and should be avoided, unless this is done for a specific reason, for example, when using some type of caching in the application.
- Requesting the same data repeatedly – ​​Refers to the unnecessary execution of queries by a software.

#### Examining Data Not Required
Once you know that you are not asking for more data than necessary, you must make sure that the DBMS is not examining more data than necessary. Some simple metrics to calculate the cost of a query are [[1]](#ref1):

- Response time;
- Numbers of examined tuples;
- Number of tuples returned.

Through these observed metrics, it becomes possible to get an idea of ​​the amount of data that MySQL had to access internally to finish the query. These three mentioned metrics are stored in a log that records all database queries that are considered to be slow. So looking at this log is a great way to find slow queries [[1]](#ref1).

Regarding the response time, it can be used as an excellent information about the time used to perform a query and, for later comparisons in order to check the effectiveness of applied optimizations [[1]](#ref1).

Regarding the examined tuples and returned tuples, although they are great metrics to analyze whether the DBMS is accessing more data than necessary, they are not perfect metrics, since not all tuple access is equal, for example, small tuples are more quick to access [[1]](#ref1).

In an ideal scenario, the number of tuples returned should be equal to the number of tuples analyzed internally by the DBMS, but in most cases this does not correspond to reality, since in a simple example of using an INNER JOIN clause, it is already possible note that each tuple is made up of data from different tuples. The ratio between returned tuples and examined tuples is typically between 1 to 1 and 1 to 10 [[1]](#ref1).

#### Optimizing Queries With COUNT() Function

To start studying this topic, it is important to understand what the SQL COUNT() function actually does when it is processed by the DBMS. This function counts values ​​and retrieved tuples, being a very common mistake to pass the name of a column inside the COUNT() function in order to obtain the number of tuples in the table. However, when specifying the name of a column or an expression inside COUNT() the result actually tells the number of times the column/expression has a value. Therefore, a very important point in relation to the optimization of queries that use the COUNT() function is to verify if the function is being used properly for the proposed context [[1]](#ref1).

If you want to obtain the number of tuples in the table, you must always use COUNT(*), so that the intention is effectively communicated and the DBMS can perform the operation with the best possible performance. Another optimization alternative would be to check if the exact number of tuples in the table is really needed for the query context. If not necessary, an approximation can be used, through the number of examined tuples brought by the use of the EXPLAIN command in a query that would use the COUNT() function [[1]](#ref1).

#### Optimizing Queries With JOIN Clause

Regarding the optimization of queries with JOIN clauses, the following points are important [[1]](#ref1):

- It is important that there are indexes in the columns used by the ON and USING clauses;
- In general, when performing JOINS, it is only necessary that there is an index in the column of the second table used in the JOIN (considering the JOIN execution order defined by the DBMS, and not the order defined in the query);
- It is recommended that all columns used by GROUP BY and ORDER BY clauses be from the same table (so that indexes can be used to perform the operation).

#### Optimizing Queries With GROUP BY and DISTINCT Clauses

For both, indexing the columns used by the clauses is the best way to optimize this type of queries. Regarding the GROUP BY clause, it is important to note that in the case of MySQL it automatically sorts the result using the columns grouped by the GROUP BY, unless the ORDER BY clause is explicitly passed. Therefore, if the order of the results is not important, a performance improvement can be obtained through the use of ORDER BY NULL, which prevents automatic sorting [[1]](#ref1).

#### Optimizing Queries With UNION Clause

Regarding the use of the UNION clause, the following points are considered important [[1]](#ref1):
- The use of clauses such as WHERE, LIMIT and ORDER BY must always be done in internal queries, and not in the temporary table created to display the results
finals;
- You must always use UNION ALL, unless there is a need to remove duplicate tuples.

#### Ooptimizing Queries With Subqueries

Regarding the use of queries with subqueries, the most important point to be mentioned, with regard to optimization, is always to give preference to the use of JOIN clauses over the use of subqueries, in all cases where such substitution if possible [[1]](#ref1).

### Indexing

The resource known as a database index corresponds to a DBMS object that allows rows of a table to be found more quickly. When a query is performed on a table looking for a record using a specific index, instead of traversing the entire table looking for the requested data, the DBMS will look inside an auxiliary structure that contains an index first. After finding what you are looking for in the index file, the DBMS will access the table rows that correspond to the index in question. In this way, it can be said that the index works as a kind of “yellow pages” of old telephone directories, of stored data [[1]](#ref1).

There are several types of indexes, and they can be used in several different ways, being interesting to know their characteristics, as well as the characteristics of the existing demands in the software that wants to access data quickly using the resource of indexes so that the best possibility can be be used in a manner consistent with such characteristics [[1]](#ref1).

A common mistake when using an index is performing operations on the index. The correct use of indexes can reduce the amount of data that the database needs to analyze and can even prevent the database from performing sort operations during the query. Contrary to what is imagined, not every index helps the bank's performance, so there are some techniques to ensure that the indexes used are actually beneficial. The real impact of using an index is directly connected to the queries that will be performed on the index available in the DBMS [[1]](#ref1).

#### Complete Index and Prefix Index

To ensure that indexes are used efficiently, they must be implemented based on the type of query expected for each table. A simple way to work with indexes is to use the full value of the attribute [[1]](#ref1).

When creating indexes for a table, it is occasionally necessary to index attributes that are very large, which causes your indexes to become slow and take up a lot of memory space. In these cases, it is possible to index only one attribute prefix [[1]](#ref1).

After obtaining the records that match the prefix, the DBMS proceeds with a query on these records, applying the WHERE clause to the rest of the attribute. The problems with using this type of index is that they decrease selectivity, in other words, they have a greater number of records per index. Also, this type of index cannot be used for sorting and grouping [[1]](#ref1).

#### Comprehensive Index Searches

In addition to all the ways to use indexes to access the rows of a table more quickly, it is also possible to perform a query without having to access the table of origin of the index. This can be done when all fields used in a query are contained within an index. When indexes are created to perform this type of query, the DBMS does not need to fetch the data contained in the table, which can drastically reduce the execution time of a query [[1]](#ref1).

This is because when there is a need to retrieve data from the table, it is necessary to use the address contained in the index to access the disk in places that are not necessarily continuous, and it may even be possible to access the disk for each desired record. In this type of query, it is only necessary to access the index structure, which is stored in an orderly manner, which also helps to reduce the number of disk accesses [[1]](#ref1).

In addition, another impacting factor is the size of an index, whose rows are much smaller than the rows of a table, which causes more items to be retrieved with each disk access [[1]](#ref1).

#### Cluster Indices

This term does not refer to a type of index in the same way as when we talk for example about a binary tree index or a hash index, but a way of organizing data on disk. In this type of configuration, the rows of a table are stored according to the index value, which causes index records with consecutive values ​​to be stored next to each other. Given its characteristic of defining the arrangement of data, there can only be one “clustered” index per table [[1]](#ref1).

By changing the way data is saved, this type of structure also changes how the data is retrieved, which can have a great positive impact when well implemented, especially when this type of structure is used without adequate analysis of the characteristics of the database. , it can severely deteriorate the performance of the DBMS. When compared to non-clustered indices, the “clustered” indices, in general, have a shorter response time, as they store the data together with the index structure itself [[1]](#ref1).

This differentiates them from non-clustered indexes, which store the indexes in their own structures along with a table row address that corresponds to each index value. And despite making index-based searches more efficient by making it possible to return multiple results that match the search value with just one disk access, these indexes make the FULL TABLE SCAN considerably slower. This type of structure can become an obstacle when inserting new data into the database. This is because the insertion speed will directly depend on the order in which the data is provided, being the ideal arrangement, in the order of the index values [[1]](#ref1).

## References

[1]  MARTINS, B; SILVA, M. Aprimoramento de desempenho de banco de dados: um estudo de caso de um Sistema Tutor Inteligente. Faculdade UnB Gama, Universidade de Brasília. Brasília p. 175. 2019.
{: #ref1}