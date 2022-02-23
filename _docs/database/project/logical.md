---
layout: default
title: Logical
nav_order: 1
description: 'Logical design'
grand_parent: Database
parent: Project
---

Logical
{: .fs-9}

Logical design
{: .fs-6 .fw-300  }

The logical design of a database is an important tool through which one can observe the schema levels of a database, that is, the levels where the data are described. Figure 6 presents the three-tier architecture of a logical database design [[1]](#ref1).

## Conceptual Model

The conceptual model is a representation that presents what data is relevant to the database, but is not concerned with how this data will be written. The most used way to represent the project at this level is the modeling based on the Entity-Relationship Model that produces the representation of the Entity Relationship Diagram [[1]](#ref1).

In an Entity Relationship Diagram, for example, for entities we use rectangles that are related through diamonds with arrows that direct the relationship. Each entity has its own attributes that are represented by circles. Circles filled with black are primary keys [[1]](#ref1).

It is also important to know the membership and cardinality ratio in each relationship.
- **Participation constraint** – Consists of the minimum number of instances of an entity present in a relationship, that is, this constraint defines whether the existence
of an entity is or is not conditional on a relationship with another entity. This constraint is also known as the minimum cardinality constraint.
- **Cardinality Ratio** – Unlike the participation constraint, the cardinality ratio determines the maximum number in which a certain entity can
participate in a relationship.
Thus, in binary relationships, that is, between two entities, the possible cardinalities are 1:1, 1:n, n:1 and m:n, which represent, respectively, one to
one, one to many, many to one and many to many.

## Logical Model

In a logical model, the representation is done by describing the database from the perspective of the DBMS user. In this way, the representation depends on the type of DBMS to be used. This template should display the tables and their column names, in addition to defining the corresponding data types for each attribute (column). The logical model of the logical design of a database can be represented textually using the notation 𝑅(𝐴1, 𝐴2, 𝐴3, ..., 𝐴𝑛), where R represents a relation of degree n, that is, a relation with n attributes [[1]](#ref1).

## Physical Model

Unlike the conceptual and logical models, the physical model details the data structures that will be used to build the database physically, and this model, as well as the logical one, depends on which DBMS will be implemented in the project [[1]](#ref1).

## References

[1]  MARTINS, B; SILVA, M. Aprimoramento de desempenho de banco de dados: um estudo de caso de um Sistema Tutor Inteligente. Faculdade UnB Gama, Universidade de Brasília. Brasília p. 175. 2019.
{: #ref1}