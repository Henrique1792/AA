SRCS= table.c 
OBJS= $(SRCS:.c=.o)


all: teste

$(OBJS): %.o : %.h

.cpp.o:
	gcc -g -Wall -c $< -o $@



teste:$(OBJS)
	g++ -g -Wall $^ main.c -o $@



run:
	./teste




clean:
	rm $(OBJS) teste
