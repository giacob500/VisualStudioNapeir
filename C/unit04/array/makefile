array:
	 cl /c search.c sort.c generate.c
	 lib /OUT:array.lib search.obj sort.obj generate.obj
	 cl /c test.c
	 link test.obj array.lib

array2:
	cl search.c sort.c generate.c -o combined

clean:
	del *.obj
	del *.lib
	del *.exe
	del *.asm