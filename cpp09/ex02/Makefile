NAME = pmergeme

FLAGS = -std=c++98 -Wall -Wextra -Werror

CPP = c++

RM = rm -rf

SRCS = main.cpp PmergeMe.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CPP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:clean

re: clean all

.PHONY:all re clean fclean