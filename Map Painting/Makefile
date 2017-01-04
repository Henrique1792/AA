SRCS= utils.c node.c map.c
OBJS= $(SRCS:.c=.o)


all: painting

$(OBJS): %.o:%.h

.c.o:
	gcc -g -Wall -c $< -o $@

painting: $(OBJS)
	gcc -g -Wall $^ main.c -o $@

run:
	./painting

debug:
	valgrind ./painting

clean:
	rm $(OBJS) painting
