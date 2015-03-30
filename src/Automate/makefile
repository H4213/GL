EDL=g++
EDLFLAGS=-o
COMP=g++
CPPFLAGS=-c 

EXE=Automate 

INT=main.h Automate.h Etat.h 
LIBS=
#At Class
LIBDIR_INSA=
#At Home
LIBDIR_HOME=



OBJ=$(INT:.h=.o)

LIBPATH=-L$(LIBDIR_INSA) -L$(LIBDIR_HOME)
INCPATH=-I$(LIBDIR_INSA) -I$(LIBDIR_HOME)

$(EXE) : $(OBJ)
	$(EDL) $(EDLFLAGS) $(EXE) $^ $(LIBPATH) $(INCPATH) $(LIBS)

%.o : %.cpp
	$(COMP) $(CPPFLAGS) $(INCPATH) $*.cpp

clean :
	rm -f *.o $(EXE) core 
