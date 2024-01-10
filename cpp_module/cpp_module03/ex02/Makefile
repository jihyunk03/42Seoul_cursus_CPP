NAME		= FragTrap

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

SRCS		= main.cpp \
			  ClapTrap.cpp \
			  ScavTrap.cpp \
			  FragTrap.cpp
INCS		= ClapTrap.hpp \
			  ScavTrap.hpp \
			  FragTrap.hpp
OBJS		= $(SRCS:.cpp=.o)


all		: $(NAME)

%.o		: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME)	: $(OBJS) $(INCS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo $(GREEN) "⚡︎	[ FragTrap ]	Ready to use FragTrap" $(RESET)

clean	:
	@$(RM) $(OBJS)
	@echo $(GREEN) "⚡︎	[ FragTrap ]	Removed Object files" $(RESET)

fclean	: clean
	@$(RM) $(NAME)
	@echo $(GREEN) "⚡︎	[ FragTrap ]	Removed FragTrap" $(RESET)

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
