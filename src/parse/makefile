

make_directory  = $(if $(call realpath, $(1)), ,$(shell mkdir -p $(1)))
YACCWORK=.yaccwork
YACCDEBUG=-DYYERROR_VERBOSE -DYYDEBUG

OBJS  = obj/cl.o
OBJS += obj/cy.o
OBJS += obj/libcy.o
LIB   = ../lib/libcyl.a

SILENCE=@

all : $(LIB)

$(LIB) : $(OBJS) 
	ar ruv $(LIB) $(OBJS) 

yacc: 
	$(SILENCE)$(call make_directory, $(YACCWORK))
	$(SILENCE)bison -v -d c.y -o $(YACCWORK)/cy.c
	$(SILENCE)flex -o$(YACCWORK)/cl.c c.l

obj/cy.o:  yacc
	$(SILENCE)gcc $(YACCDEBUG) -I$(YACCWORK) -c -o $@ $(YACCWORK)/cy.c 

obj/cl.o:  yacc
	$(SILENCE)gcc $(YACCDEBUG) -I$(YACCWORK) -c -o $@ $(YACCWORK)/cl.c

obj/%.o : %.c
	@echo compiling $<
	$(SILENCE)gcc -Iinclude -I$(YACCWORK) -c -o $@ $<
	

clean:
	rm -rf .yaccwork
	rm -f c.tab.c c.tab.h
	rm -f obj/*.[ao]
	rm -f $(LIB)
