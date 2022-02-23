---
layout: default
title: Database 
nav_order: 4
description: 'What are databases'
has_children: true
permalink: /database 
---

Database
{: .fs-9}

What are databases
{: .fs-6 .fw-300  }

<a style="color:white" href="#DBMS">DBMS</a>
{: .label .label-red } 

Database corresponds to a set of data that have some relationship with each other and serve some specific purpose or purposes when it comes to information technology, the meaning of database ends up carrying some other implicit concepts, such as: it symbolizes something of the real world; it has data that is related and has some meaning to its context; exists to serve a specific purpose or purposes [[1]](#ref1).

A database can be created and manipulated without the use of tools specifically developed for this purpose, but the advance in data storage technologies currently offers systems that allow for a more agile and secure management. This integration of storage resources with computer programs that allow the management of these stored data is called Database Management System (DBMS). A DBMS facilitates the access and safe manipulation of data in the technological resources available to keep the data in a coherent way to meet the demands of its users [[1]](#ref1).

## Database Management System (DBMS)
{: #DBMS}
A Database Management System (DBMS) is a software whose main objective is to facilitate the management of implemented databases. Its general purpose is to provide interfaces that allow organizing and manipulating data that is stored in a persistent and non-volatile manner [[1]](#ref1). Some of the main operations that become possible when using a DBMS are:
- Create databases;
- Delete databases;
- Update databases;
- Add data in databases;
- Retrieve data from databases;
- Update data from databases;
- Remove data from databases.

The use of a DBMS provides several operational advantages over the databases that are implemented, promoting a more detailed management of resources and manipulations with analyzes relevant to the understanding of its operation [[1]](#ref1).
- **Redundancy control** – It becomes easier to store non-repeated data, consequently improving the integrity of the database.
- **Authorization control** – Using a DBMS, it becomes possible to easily specify who is authorized to perform operations on specific data and which operations can be performed on tables or structures provided by the DBMS.
- **Persistent storage** – It is possible to store data structures persistently, unlike what normally occurs when using data structures within programming languages, in which data values ​​are discarded when the program ends, as they were stored in memory .
- **Efficient query** – A DBMS uses techniques to ensure that even with persistent storage there are mechanisms to retrieve data quickly and efficiently.
- **Backup and recovery** – The DBMS has resources to recover from failures caused by logical and hardware problems. Thus, if an error in a transaction or a catastrophic disk failure occurs, the DBMS must provide, respectively, mechanisms for recovering or restoring a data backup.
- **Multiple interfaces** – A DBMS provides different user interfaces for its different users. For example, the interface for use through programming languages, graphical interface, interface for using the command line, among others that are relevant to the demands that need to be met by their users or processing.
- **Complex relationships** - A DBMS needs to be able to represent complex relationships between data and, in addition, to make the retrieval and updating of these data effective through their relationships
- **Integrity restrictions** – Using a DBMS, it must be possible to impose restrictions on the data, such as: defining the type of data to be used for each attribute (integer, date, text, etc.), defining the number of characters minimum and maximum, define that a data must be related to another data, define that a data must always have a unique value, etc.
- **Define deduction and actions** – In some DBMSs is possible to define rules to deduct new data based on the data stored in your available database. And traditionally, it is possible to use mechanisms called triggers to execute operations in specific situations. These operations are normally recorded in the DBMS itself and may involve other objects stored in the DBMS called procedures. An example of the use of a trigger would be when a new sale is made and inserted into the database, a trigger would be triggered to update the table responsible for the stock of items in the system or application


## References

[1]  MARTINS, B; SILVA, M. Aprimoramento de desempenho de banco de dados: um estudo de caso de um Sistema Tutor Inteligente. Faculdade UnB Gama, Universidade de Brasília. Brasília p. 175. 2019.
{: #ref1}