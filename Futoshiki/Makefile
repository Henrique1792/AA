SRCS= quick.c inequation.c table.c files.c rules.c brute.c
OBJS= $(SRCS:.c=.o)


all: futoshiki

$(OBJS): %.o : %.h

.c.o:
	gcc -g -Wall -c $< -o $@

futoshiki: $(OBJS)
	gcc -g -Wall $^ main.c -o $@

run:
	./futoshiki

debug:
	valgrind ./futoshiki

clean:
	rm $(OBJS) futoshiki
