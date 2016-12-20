SRCS=person.cpp tinder.cpp
OBJS=$(SRCS:.cpp=.o)
EXE=gale_shapley
GCC= g++

all: gale_shapley

$(OBJS)=%.o:%.h

.c.o:
	$(GCC) -g -Wall -c $< -o $@

gale_shapley: $(OBJS)
	$(GCC) -g -Wall $^ main.c -o $(EXE)

run:
	./_shapley

debug:
	valgrind ./$(EXE)

clean:
	rm $(OBJS) $(EXE)
