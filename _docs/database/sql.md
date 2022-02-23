---
layout: default
title: SQL
nav_order: 4
description: 'SQL'
parent: Database
---

SQL
{: .fs-9}

Structured Query Language
{: .fs-6 .fw-300  }

<a style="color:white" href="#ACID">ACID</a>
{: .label .label-purple } 

<a style="color:white" href="#DDLDML">DDL and DML</a>
{: .label .label-purple } 

Structured Query Language (SQL) is a language that operates on persistently stored data. Through SQL, data definition and manipulation operations became possible using a high-level language [[1]](#ref1).

{: #DDLDML}
Data Definition and Manipulation in a Relational DBMS, operations are commonly divided into the use of two languages ​​that correspond to their specific SQL commands: Data Definition Language (DDL) and Data Manipulation Language (DML) [[1]](#ref1).

The DDL is responsible for the operations that define the way in which the data will be defined and organized to be recorded in one or more databases. Through the DDL instructions, tables (relations) or data structures will be defined, as well as new data types that the DBMS can use in its processing [[1]](#ref1).

DML, on the other hand, involves the instructions responsible for manipulating the data that are stored in tables or data structures defined by the DDL. By means of DML commands it is possible to consult data already stored in the DBMS, insert new data in its available tables, change the stored data or delete the persistent data stored in the DBMS. These operations, considering an SQL context, can be performed, respectively, by SELECT, INSERT, UPDATE and DELETE statements [[1]](#ref1).

## Schemes
It aims to group tables and other objects belonging to the same context involving users and specific applications.

## Transactions
A transaction is a set of operations that is performed as a single logical unit of work, and as such is either performed in its entirety or not performed at all. That is, if any of the operations that are part of the transaction fails, all operations of the transaction, both those that have already been executed and those that have not, are canceled [[1]](#ref1).

- START TRANSACTION – Through this command, the MySQL DBMS disables the autocommit mode, which is enabled by default in this DBMS. This means that MySQL will not effectively save changes made to disk at the time the command is executed, as opposed to when autocommit mode is active, where changes are persisted as soon as possible.
- COMMIT – This command makes the changes made through the commands executed during the current transaction become permanent, that is, saved on disks, so that they can be seen by other sessions.
- ROLLBACK – This command cancels all the modifications made through the commands executed during the current transaction. That is, changes are not persisted to disk.

## ACID
{: #ACID}
SQL often works in a mode called autocommit. This means that unless the database user explicitly starts and ends a transaction, SQL will execute each operation as a separate transaction and will therefore apply the ACID property test to COMMIT each operation [[1]](#ref1).

### Atomicity

Ensures that a transaction will always be a single logical unit of DBMS processing. Thus, a transaction is executed in its entirety or nothing in it will be executed [[1]](#ref1).

### Consistency
It guarantees that the DBMS will always move from a consistent state to another state consistent with transaction processing. If an error occurs in any of the instructions, the changes in the other instructions will never actually be reflected in the DBMS [[1]](#ref1).

### Isolation
It guarantees that a transaction will only have access to the result of another transaction after the moment when this other transaction is complete, that is, it has been fully executed [[1]](#ref1).

### Durability
It guarantees that once the transaction has successfully completed, the changes made by it will be permanent. Even if an error occurs in the DBMS, the data must be preserved in its new state [[1]](#ref1).

## References

[1]  MARTINS, B; SILVA, M. Aprimoramento de desempenho de banco de dados: um estudo de caso de um Sistema Tutor Inteligente. Faculdade UnB Gama, Universidade de Brasília. Brasília p. 175. 2019.
{: #ref1}