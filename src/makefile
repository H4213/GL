#-----------------------------------------------------------------------------------
LIBPATH =
LIBS =   -lboost_regex
COMP = g++
COMPFLAGS = -c
EXEC = lut 
EXECT = ../Tests/lut
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
all	: $(EXEC) $(EXECT)
$(EXEC) : $(OBJ)
	$(ECHO) Edl $(EXEC)
	$(EDL) $(EDLFLAGS) $(EXEC) $(OBJ) $(LIBPATH) $(LIBS)

$(EXECT) : $(OBJ)
	$(ECHO) Edl $(EXECT)
	$(EDL) $(EDLFLAGS) $(EXECT) $(OBJ) $(LIBPATH) $(LIBS)



%.o 	: %.cpp
	$(ECHO) compil de $<
	$(COMP) $(COMPFLAGS) $(INCPATH) $<

$(CLEAN):
	$(ECHO) Nettoyage
	$(RM) $(RMFLAGS) *.o $(EXEC) core
