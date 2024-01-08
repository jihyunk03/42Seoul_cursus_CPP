NAME		= FixedPoint

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

SRCS		= main.cpp \
			  Fixed.cpp
INCS		= Fixed.hpp
OBJS		= $(SRCS:.cpp=.o)


all		: $(NAME)

%.o		: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME)	: $(OBJS) $(INCS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo $(GREEN) "⚡︎	[ FixedPoint ]	Ready to use FixedPoint" $(RESET)

clean	:
	@$(RM) $(OBJS)
	@echo $(GREEN) "⚡︎	[ FixedPoint ]	Removed Object files" $(RESET)

fclean	: clean
	@$(RM) $(NAME)
	@echo $(GREEN) "⚡︎	[ FixedPoint ]	Removed FixedPoint" $(RESET)

re		:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY	: all clean fclean re

RESET	= "\x1b[0m"
GREY	= "\x1b[30m"
RED		= "\x1b[31m"
GREEN	= "\x1b[32m"
YELLOW	= "\x1b[33m"
BLUE	= "\x1b[34m"
PURPLE	= "\x1b[35m"
CYAN	= "\x1b[36m"
WHITE	= "\x1b[37m"
