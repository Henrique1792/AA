SRCS= inequation.c table.c files.c 
OBJS= $(SRCS:.c=.o)


all: teste

$(OBJS): %.o : %.h

.c.o:
	gcc -g -Wall -c $< -o $@



teste:$(OBJS)
	gcc -g -Wall $^ testmain.c -o $@



run:
	./teste

debug:
	valgrind ./teste


clean:
	rm $(OBJS) teste
