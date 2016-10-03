SRCS= table.c 
OBJS= $(SRCS:.cpp=.o)


all: teste

$(OBJS): %.o : %.h

.cpp.o:
	gcc -g -Wall -c $< -o $@



teste:$(OBJS)
	g++ -g -Wall $^ main.cpp -o $@



run:
	./teste




clean:
	rm $(OBJS) teste
