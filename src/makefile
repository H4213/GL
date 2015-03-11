#-----------------------------------------------------------------------------------
LIBPATH =
LIBS =   -lboost_regex
COMP = g++
COMPFLAGS = -c
EXEC = Grammaire
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
all	: $(EXEC)
$(EXEC) : $(OBJ)
	$(ECHO) Edl $(EXEC)
	$(EDL) $(EDLFLAGS) $(EXEC) $(OBJ) $(LIBPATH) $(LIBS)


%.o 	: %.cpp
	$(ECHO) compil de $<
	$(COMP) $(COMPFLAGS) $(INCPATH) $<

$(CLEAN):
	$(ECHO) Nettoyage
	$(RM) $(RMFLAGS) *.o $(EXEC) core
