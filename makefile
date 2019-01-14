CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = utility.o menu.o queue.o main.o

SRCS = utility.cpp menu.cpp queue.cpp main.cpp

HEADERS = utility.hpp menu.hpp queue.hpp 

main: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o lab7 

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	$(RM) lab7 utility.o menu.o queue.o main.o

