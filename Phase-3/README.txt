This directory contains the files comprising the skeleton of the C
compiler "pcc3".


Source files:

Makefile	- Compiler maintenance
defs.h		- Global definitions
gram.y		- The skeleton grammar for Pascal
main.c		- The main routine
message.c	- Message handling routines
message.h	- Definitions for message.c
scan.l		- The specification of the lexical scanner
symtab.c	- Symbol table maintenance
symtab.h	- Definitions for symtab.c
types.c		- Processes Pascal type information
types.h		- Definitions for types.c
backend-x86.c	- Routines for generating x86 assembly code
backend-x86.h	- Definitions for backend-x86.c
utils.c		- Miscellaneous utilities

Documentation: Tree.c, tree.h, encode.c, encode.h, gram.y are edited by me. Code is working fine with 80%, 90% and 100% well except for couple of mismatches in the output file comparison.  

README.txt	- This file
