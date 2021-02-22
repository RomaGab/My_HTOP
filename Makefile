##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

CFLAGS	=	-Wall -Wextra -Werror -W -g3 -lsfml-graphics -lsfml-window -lsfml-system -lncurses

CPPFLAGS	=	-I./include/

LDLIBS	=	-lcriterion

LD		=	g++

NAME	=	MyGKrellm

MAIN	=	src/main.cpp

SRC		=	src/ncurses/InitNcurses.cpp			\
			src/SFML/SFML.cpp					\
			src/MonitorDisplay.cpp				\
			src/modules/NameModule.cpp			\
			src/modules/DateModule.cpp			\
			src/modules/OSModule.cpp			\
			src/modules/CPUModule.cpp			\
			src/modules/RamModule.cpp			\
			src/modules/NetworkModule.cpp		\

OBJ		=	$(SRC:.cpp=.o) $(MAIN:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(LD) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcno
	rm -f vgcore.*
	rm -f *.report

fclean:		clean
	rm -f $(NAME)
	rm -f tests_run

re:	fclean all

tests_run: CFLAGS += --coverage
tests_run: LDLIBS += -lcriterion
tests_run:
	$(LD) -o tests_run $(SRC) $(TESTSRC) $(CFLAGS) $(LDFLAGS) $(LDLIBS)
	./tests_run

debug:
	$(LD) -g -o $(NAME) $(MAIN) $(SRC) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS)

.PHONY: all clean fclean re tests_run
