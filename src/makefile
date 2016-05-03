
LMNAME  = cflowmake
make_directory  = $(if $(call realpath, $(1)), ,$(shell mkdir -p $(1)))
YACCWORK=.yaccwork
#YACCDEBUG=-DYYERROR_VERBOSE -DYYDEBUG -DDEBUG
YACCDEBUG=-DYYERROR_VERBOSE -DYYDEBUG 

HEADDIR=-Iinclude 

OBJ_DIR = ./obj
SRCS    = $(wildcard *.cpp)
OBJS    = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.cpp=.o)))
OBJS   += $(OBJ_DIR)/cy.o
OBJS   += $(OBJ_DIR)/cl.o

LIB_DIR = ./lib
LIB     = $(LIB_DIR)/libcyl.a

SILENCE=@

all : $(LIB)
	@echo "make binary $(LMNAME)"
	$(SILENCE)g++ -o $(LMNAME) $(OBJ_DIR)/main.o -L$(LIB_DIR)  -lcyl -ll

$(LIB) : $(OBJS) 
	@[ -d $(LIB_DIR)  ]; mkdir -p $(LIB_DIR)
	@echo linking $@
	$(SILENCE)ar r $(LIB) $(OBJS) 

yacc: 
	@[ -d $(YACCWORK) ]; mkdir -p $(YACCWORK)
	$(SILENCE)bison -v -d c.y -o $(YACCWORK)/cy.cpp
	$(SILENCE)flex -o$(YACCWORK)/cl.cpp c.l

$(OBJ_DIR)/cy.o:  yacc
	@[ -d $(OBJ_DIR)  ]; mkdir -p $(OBJ_DIR)
	$(SILENCE)g++ -g $(YACCDEBUG) -include pars/cyparse.h -include pars/cytypes.h $(HEADDIR) -I$(YACCWORK) -c -o $@ $(YACCWORK)/cy.cpp

$(OBJ_DIR)/cl.o:  yacc
	@[ -d $(OBJ_DIR)  ]; mkdir -p $(OBJ_DIR)
	$(SILENCE)g++ -g $(YACCDEBUG) -include pars/cyparse.h -include pars/cytypes.h $(HEADDIR) -I$(YACCWORK) -c -o $@ $(YACCWORK)/cl.cpp

$(OBJ_DIR)/%.o : %.cpp
	@[ -d $(OBJ_DIR)  ]; mkdir -p $(OBJ_DIR)
	@echo compiling $<
	$(SILENCE)g++ -g $(HEADDIR) -I$(YACCWORK) -c -o $@ $<

clean:
	rm -rf .yaccwork
	rm -f c.tab.c c.tab.h
	rm -f $(OBJ_DIR)/*.[ao]
	rm -f $(LIB)
