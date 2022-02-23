---
layout: default
title: Relational
nav_order: 1
description: 'Relational Data Model'
grand_parent: Database
parent: DataModel
---

Relational
{: .fs-9}

Relational Data Model
{: .fs-6 .fw-300  }

A relational DBMS (one that uses the relational model) corresponds to a set of tables, mainly also called relations, which represents something in the real world, so that the table rows, called tuples, represent relations between a set of values. Thus, the table would represent a set of entities and each row of the table would represent an entity[[1]](#ref1).

Thinking about the fact that a set of entities is considered as a table, the headers representing each column of the table are called attributes, which have an attribute that is unique, which is selected for the column of the table[[1]](#ref1).

The following are important concepts about relational DBMSs:
- **Entity** – An entity is an object (something) in the real world that can be distinguished from another object. In the table representation example, each account is an entity. Other examples of entity could be: people, sales, products, etc.
- **Relationship** – It is the association between entities. For example, in the case where there are entities “sale” and “product”, these entities will certainly have a relationship, as the sale will be being made of some product.
- **Table** – It is a set of entities instantiated in the table that stores their respective data. Because of similarities with the mathematical concept of relationship, tables are also called relationships.
- **Line** – These are the entities of a table. Also because of similarities with a mathematical concept, the rows (records) of a table are also called tuples.
- **Attribute** – It is the “header” of each of the columns of the tables and describes each entity stored.
- **Domain** – These are the values ​​allowed for each attribute. For example: the attribute X of the relation Y must only accept integers.
- **Primary key** – It is the attribute of the relation used to uniquely identify each one of the tuples, that is, it is the main way to specifically identify a row of a relation
- **Foreign key** – It is the relation attribute used to reference the key
primary of another relationship, establishing a relationship between the relationships.
- **Candidate key** – It is the attribute that has the potential to be a unique identifier among the rows of the table, but that for some specific reason was not chosen to be responsible for such identification in the DBMS. This task belongs to the table's primary key.
- **Persistent data** – Persistent data is that data that continues to exist after the end of the process that created it because it is saved in a non-volatile data storage structure, such as HD (Hard Disk), CD-ROM ( Compact Disk Read-Only Memory) among others.
- **Transaction** – A transaction is a set of operations that are executed as if they were a single execution block. And if so, this block is executed in its entirety or not at all.
- **Non-catastrophic failure** – Failure in which the system log is not affected and the DBMS is able to apply a recovery procedure to return to normal operation.
- **Catastrophic failure** – Unlike non-catastrophic failure, in this type of failure, such as disk failure, the system log and/or the database itself are affected. The most used technique to deal with this type of failure is the database backup, which is usually performed by copying it to another cheaper storage medium.

## Relational Algebra

Relational algebra are operators that return a relation. These operators that make up such a collection are responsible for writing relational expressions, which must serve a series of purposes, such as delimiting the scope for a database search, defining the data to which some security restriction will be applied, etc. Thus, these operators aim to represent the user's intention in performing operations on the database [[1]](#ref1). These are defined nine operations for working with relational algebra:

- Union;
- Intersection;
- Difference;
- Product.

These four operations come from set theory, from mathematics.

- Select;
- Project;
- Join;
- Divide.

They apply specifically to the relational data model.

- Assignment.

## References

[1]  MARTINS, B; SILVA, M. Aprimoramento de desempenho de banco de dados: um estudo de caso de um Sistema Tutor Inteligente. Faculdade UnB Gama, Universidade de Brasília. Brasília p. 175. 2019.
{: #ref1}