CXX = g++;
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = webserv

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all
