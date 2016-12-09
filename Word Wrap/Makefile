SRCS= utils.c ww.c
OBJS= $(SRCS:.c=.o)


all: word_wrap 

$(OBJS): %.o : %.h

.c.o:
	gcc -g -Wall -c $< -o $@

word_wrap: $(OBJS)
	gcc -g -Wall $^ main.c -o $@

run:
	./word_wrap

debug:
	valgrind ./word_wrap

clean:
	rm $(OBJS) word_wrap
