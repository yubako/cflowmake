

make_directory  = $(if $(call realpath, $(1)), ,$(shell mkdir -p $(1)))
YACCWORK=.yaccwork
YACCDEBUG=-DYYERROR_VERBOSE -DYYDEBUG -DDEBUG
#YACCDEBUG=-DYYERROR_VERBOSE -DYYDEBUG 

HEADDIR=-Iinclude 

OBJS  = obj/cl.o
OBJS += obj/cy.o
OBJS += obj/libcy.o
OBJS += obj/psbuff.o
OBJS += obj/statement.o
OBJS += obj/expression.o
OBJS += obj/declaration.o
OBJS += obj/translationunit.o
OBJS += obj/CyFlowDotNode.o
OBJS += obj/CyFlowVisitor.o
OBJS += obj/CyFlowDotGraph.o
LIB   = lib/libcyl.a

SILENCE=@

all : $(LIB)

$(LIB) : $(OBJS) 
	ar rv $(LIB) $(OBJS) 

yacc: 
	$(SILENCE)$(call make_directory, $(YACCWORK))
	$(SILENCE)bison -v -d c.y -o $(YACCWORK)/cy.cpp
	$(SILENCE)flex -o$(YACCWORK)/cl.cpp c.l

obj/cy.o:  yacc
	$(SILENCE)g++ -g $(YACCDEBUG) -include pars/cyparse.h -include pars/cytypes.h $(HEADDIR) -I$(YACCWORK) -c -o $@ $(YACCWORK)/cy.cpp

obj/cl.o:  yacc
	$(SILENCE)g++ -g $(YACCDEBUG) -include pars/cyparse.h -include pars/cytypes.h $(HEADDIR) -I$(YACCWORK) -c -o $@ $(YACCWORK)/cl.cpp

obj/%.o : %.cpp
	@echo compiling $<
	$(SILENCE)g++ -g $(HEADDIR) -I$(YACCWORK) -c -o $@ $<
	

clean:
	rm -rf .yaccwork
	rm -f c.tab.c c.tab.h
	rm -f obj/*.[ao]
	rm -f $(LIB)
