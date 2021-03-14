Tool chain: Microsoft Compiler

Install program:
1)	Open command prompt in this folder.
	Make sure Microsoft Compiler is installed.

2) 	Type "nmake build"
	to build the program.

3) 	Type "jdoc -i <input_file.java> -o <output_file>"
	to execute the program trough the jdoc.exe application.

	ATTENTION:
	- When launching the program, input ("-i <input_file.java>")
	and output ("-o <output_file>") order can be inverted.
	- Input ("-i <input_file.java>") must be a .java file.

Uninstall program:
1)	Type "nmake clean"
	to delete .obj and .exe files