NAME		= AForm

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

SRCS		= main.cpp \
			  Bureaucrat.cpp \
			  AForm.cpp \
			  ShrubberyCreationForm.cpp \
			  RobotomyRequestForm.cpp \
			  PresidentialPardonForm.cpp
INCS		= Bureaucrat.hpp \
			  AForm.hpp \
			  ShrubberyCreationForm.hpp \
			  RobotomyRequestForm.hpp \
			  PresidentialPardonForm.hpp
OBJS		= $(SRCS:.cpp=.o)


all		: $(NAME)

%.o		: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME)	: $(OBJS) $(INCS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo $(GREEN) "⚡︎	[ AForm ]	Ready to use AForm" $(RESET)

clean	:
	@$(RM) $(OBJS)
	@echo $(GREEN) "⚡︎	[ AForm ]	Removed Object files" $(RESET)

fclean	: clean
	@$(RM) $(NAME)
	@echo $(GREEN) "⚡︎	[ AForm ]	Removed AForm" $(RESET)

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
