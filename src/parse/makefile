

make_directory  = $(if $(call realpath, $(1)), ,$(shell mkdir -p $(1)))
YACCWORK=.yaccwork
YACCDEBUG=-DYYERROR_VERBOSE -DYYDEBUG -DDEBUG
#YACCDEBUG=-DYYERROR_VERBOSE -DYYDEBUG 

OBJS  = obj/cl.o
OBJS += obj/cy.o
OBJS += obj/libcy.o
OBJS += obj/psbuff.o
LIB   = ../lib/libcyl.a

SILENCE=@

all : $(LIB)

$(LIB) : $(OBJS) 
	ar ruv $(LIB) $(OBJS) 

yacc: 
	$(SILENCE)$(call make_directory, $(YACCWORK))
	$(SILENCE)bison -v -d c.y -o $(YACCWORK)/cy.cpp
	$(SILENCE)flex -o$(YACCWORK)/cl.cpp c.l

obj/cy.o:  yacc
	$(SILENCE)g++ -g $(YACCDEBUG) -include cyparse.h -include cytypes.h -Iinclude -I$(YACCWORK) -c -o $@ $(YACCWORK)/cy.cpp

obj/cl.o:  yacc
	$(SILENCE)g++ -g $(YACCDEBUG) -include cyparse.h -include cytypes.h -Iinclude -I$(YACCWORK) -c -o $@ $(YACCWORK)/cl.cpp

obj/%.o : %.cpp
	@echo compiling $<
	$(SILENCE)g++ -g -Iinclude -I$(YACCWORK) -c -o $@ $<
	

clean:
	rm -rf .yaccwork
	rm -f c.tab.c c.tab.h
	rm -f obj/*.[ao]
	rm -f $(LIB)
