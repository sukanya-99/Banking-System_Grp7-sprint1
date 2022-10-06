OBJS = main.o Functions.o Utilities.o
HEAD = Utility.h Function.h
PM = main.c
UTIL = Utility.c
FUNC = Functions.c
CL = *.o
G = gcc -o
C = gcc -c
T = test

menu.o: $(PM) $(HEAD)
	$(C) $(PM)
	
submenu.o: $(UTIL) $(HEAD)
	$(C) $(SM)

func.o: $(FUNC) Function.h
	$(C) $(FUNC)

clean: 
	rm $(CL)
	rm $(T)
