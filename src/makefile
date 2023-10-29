CC = g++  
CFLAGS = -Wall -g  
  
SRCS = $(wildcard *.cpp)  
OBJS = $(SRCS:.cpp=.o)  
  
program: $(OBJS)  
 $(CC) $(CFLAGS) -o $@ $^  
  
%.o: %.cpp  
 $(CC) $(CFLAGS) -c $<