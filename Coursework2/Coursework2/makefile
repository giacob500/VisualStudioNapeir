buildandexeA:
	cl /c /EHsc symbol_table_partA.cpp infotoconsole.cpp
	link symbol_table_partA.obj infotoconsole.obj
	symbol_table_partA test4.c
	
buildoldA:
	cl /c /EHsc symbol_table_partA.cpp infotoconsole.cpp
	link symbol_table_partA.obj infotoconsole.obj
	symbol_table_partA test4.c

exeA:
	symbol_table_partA test4.c

buildandexeB:
	cl /c /EHsc symbol_table_partB.cpp infotoconsole.cpp BinaryTree.cpp
	lib BinaryTree.obj
	link symbol_table_partB.obj infotoconsole.obj BinaryTree.lib
	symbol_table_partB test4.c
	
exeB:
	symbol_table_partB test4.c

clean:
	del *.obj
	del *.lib
	del *.exe