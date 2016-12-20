SRCS=  person.c matchup.c
LIB= libshapley.so
OBJS= $(SRCS:.c=.o)


all: gale_shapley

$(OBJS): %.o : %.h

.c.o:
	gcc -g -Wall -c $< -o $@

$(LIB): $(OBJS) 
	gcc -shared -o $@ $^

gale_shapley: $(LIB)
	gcc -L/henrique/Documents/AA/Gale_Shapley -Wl,-rpath=henrique/Documents/AA/Gale_Shapley -g -Wall main.c -o $@  $^ 

run:
	./gale_shapley

debug:
	valgrind ./gale_shapley

clean:
	rm $(OBJS) libshapley.so gale_shapley
