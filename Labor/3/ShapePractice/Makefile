CC = g++
CFLAGS = -g -std=c++11 -Wall
LDFLAGS =

SRCS = main.cpp rectangle.cpp circle.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = my_program

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC) $(LDFLAGS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

rectangle.o: rectangle.cpp
	$(CC) $(CFLAGS) -c $< -o $@

circle.o: circle.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)