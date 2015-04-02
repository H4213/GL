#-----------------------------------------------------------------------------------
LIBPATH =
LIBS =   -lboost_regex
COMP = g++
COMPFLAGS = -c
EXEC = lut 
EXECTEST = ../Tests/lut
CLEAN = clean
INT = $(wildcard *.cpp)
REAL = ${INT:.h =.cpp}
OBJ = ${INT:.cpp=.o}
EDL = g++
EDLFLAGS = -o
RM = rm
ECHO = echo
RMFLAGS = -f
INCPATH =
SRCPATH = 
#====================================================================================
.PHONY 	: $(CLEAN)
all	: $(EXEC) $(EXECTEST)
$(EXEC) : $(OBJ)
	$(ECHO) Edl $(EXEC)
	$(EDL) $(EDLFLAGS) $(EXEC) $(OBJ) $(LIBPATH) $(LIBS)

$(EXECTEST) : $(OBJ)
	$(ECHO) Edl $(EXECTEST)
	$(EDL) $(EDLFLAGS) $(EXECTEST) $(OBJ) $(LIBPATH) $(LIBS)


%.o 	: %.cpp
	$(ECHO) compil de $<
	$(COMP) $(COMPFLAGS) $(INCPATH) $<

$(CLEAN):
	$(ECHO) Nettoyage
	$(RM) $(RMFLAGS) *.o $(EXEC) core
