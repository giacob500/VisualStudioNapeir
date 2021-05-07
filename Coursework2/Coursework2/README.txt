Tool chain: Microsoft Compiler

Install program:
1)	Open command prompt in this folder.
	Make sure Microsoft Compiler is installed.

2) 	Type "nmake buildA"
	to build the program using no binary tree.
	Type "nmake buildB"
	to build the program using binary tree.
	Type "nmake buildall"
	to build both versions of the program.

3) 	Type "symbol_table_partA <inputfile.c>"
	to execute the program trough the its .exe
	Type "symbol_table_partB <inputfile.c>"
	to execute the program trough the its exe

	ATTENTION:
	- You can't run a program if not builded.
	If only buildA has been executed, only
	symbol_table_partA can run. likewise for B.
	- Input file must be a .c file.

Uninstall program:
1)	Type "nmake clean"
	to delete .obj .lib .exe files