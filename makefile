out :structure.o mainmenu.o insert.o delete.o sort.o save.o read.o modify.o print.o
	cc structure.h mainmenu.c delete.h sort.h save.h read.h modify.h print.h -o out
structure.o:structure.h
	cc -c structure.h
mainmenu.o:mainmenu.c
	cc -c mainmenu.c
insert.o:insert.h
	cc -c insert.h
delete.o:delete.h
	cc -c delete.h
sort.o:sort.h
	cc -c sort.h
save.o:save.h
	cc -c save.h
read.o:read.h
	cc -c read.h
modify.o:modify.h
	cc -c modify.h
print.o:print.h
	cc -c print.h
clean:
	rm -f out*.o
