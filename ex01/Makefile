# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 22:47:55 by ibertran          #+#    #+#              #
#    Updated: 2024/09/18 21:16:18 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = Serializer

# *** FILES ****************************************************************** #

MAKE_DIR := .make/
BUILD_DIR := $(MAKE_DIR)$(shell git branch --show-current 2>/dev/null)/

SRCS_DIR = srcs/
SRCS = $(addsuffix .cpp, $(SRC))

OBJS = $(patsubst %.cpp,$(BUILD_DIR)%.o,$(SRCS))

DEPS = $(patsubst %.o,%.d,$(OBJS))

SRC = \
	main \

CLASSES_DIR = Classes/
CLASSES = \
	Serializer

SRC += $(patsubst %,$(CLASSES_DIR)%,$(CLASSES))

INTERFACES_DIR = $(SRCS_DIR)Interfaces/

# *** LIBRARIES && INCLUDES  ************************************************* #

INCS_DIR = incs/
INCS = \
	$(INCS_DIR) \
	$(SRCS_DIR)$(CLASSES_DIR) \
	$(INTERFACES_DIR) \

# *** CONFIG ***************************************************************** #

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

DEFINES		=

CPPFLAGS 	=	$(addprefix -I, $(INCS)) \
				$(addprefix -D, $(DEFINES)) \
				-MMD -MP \

MAKEFLAGS	=	--no-print-directory

# *** TARGETS **************************************************************** #

.PHONY : all
all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(BUILD_DIR)%.o : $(SRCS_DIR)%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY : clean
clean :
	rm -rf $(BUILD_DIR)

.PHONY : fclean
fclean :
	rm -rf $(MAKE_DIR) $(NAME)

.PHONY : re
re : fclean
	$(MAKE)

.PHONY : run
run : $(NAME)
	./$(NAME)

.PHONY : print-%
print-% :
	@echo $(patsubst print-%,%,$@)=
	@echo $($(patsubst print-%,%,$@))

# *** SPECIAL TARGETS ******************************************************** #

-include $(DEPS)

.DEFAULT_GOAL := all
