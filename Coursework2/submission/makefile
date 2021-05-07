buildall: buildA buildB

buildA:
	cl /c /EHsc symbol_table_partA.cpp infotoconsole.cpp typevectors.cpp typevectors.cpp
	link symbol_table_partA.obj infotoconsole.obj typevectors.obj
	@echo symbol_table_partA.exe ready to execute!

buildB:
	cl /c /EHsc symbol_table_partB.cpp infotoconsole.cpp typevectors.cpp BinaryTree.cpp
	lib BinaryTree.obj
	link symbol_table_partB.obj infotoconsole.obj typevectors.obj BinaryTree.lib
	@echo symbol_table_partB.exe ready to execute!
	
clean:
	del *.obj
	del *.lib
	del *.exe
	@echo directory cleaned!