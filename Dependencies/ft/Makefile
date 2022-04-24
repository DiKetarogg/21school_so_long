# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 04:30:43 by jzoltan           #+#    #+#              #
#    Updated: 2022/02/09 09:56:50 by jzoltan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#*
all: compile
.SUFFIXES:
#*
#* ************************************************************************** *#
#*                              Project Type                                  *#
#* ************************************************************************** *#
#*
LIBRARY         = ;
#*
#* ************************************************************************** *#
#*                             Executable name                                *#
#* ************************************************************************** *#
#*
NAME            =libft.a
DEBUG_NAME      =
#*
#* ************************************************************************** *#
#*                               Run Arguments                                *#
#* ************************************************************************** *#
#*
RUN                     =
#*
#* ************************************************************************** *#
#*                          Compilation variables                             *#
#* ************************************************************************** *#
#*
DEBUG_PROGRAM           =gdb -tui -arg
SRCS_EXT                =.c
OBJS_EXT                =.o
HEADER_EXT              =.h
DFILES_EXT              =.d
CC                      =cc
ARCHIVE                 =ar rc
CFLAG                   =-Wextra -Wall -Werror -Ofast
DEBUG_FLAG              =-g3 -Wextra -Wall -Werror
DFLAG                   =-MT $@ -MD -MP -MF $(DFILES_DIR)/$*$(DFILES_EXT)
CLINK                   =
DEPENDENCIES_PATHS      =
#*
#* ************************************************************************** *#
#*                               Directories                                  *#
#* ************************************************************************** *#
#*
SRCS_DIR        =Sources
INCLUDES_DIR    =Includes
OBJS_DIR        =Objects
DFILES_DIR      =HeaderDependencies
DEPENDENCIES    =Dependencies
#*
#* ************************************************************************** *#
#*                                  Files                                     *#
#* ************************************************************************** *#
#*
OUTPUT_SOURCES          =ft_print ft_print_flush ft_print_int ft_print_save \
	ft_print_str ft_print_get_args

SOURCES_NAME            = ft_memset ft_strjoin is_smth is_smth2 is_smth3 lib \
	ft_array ft_itoa ft_rand $(addprefix output/, $(OUTPUT_SOURCES))


BONUS_SOURCES_NAME      =

MAIN_NAME               =

BONUS_MAIN_NAME         =
#*
#* ************************************************************************** *#
#*                               Conversions                                  *#
#* ************************************************************************** *#
#*
SOURCES                 =$(addsuffix $(SRCS_EXT), $(SOURCES_NAME))
BONUS_SOURCES           =$(addsuffix $(SRCS_EXT), $(BONUS_SOURCES_NAME))
MAIN                    =$(addsuffix $(SRCS_EXT), $(MAIN_NAME))
BONUS_MAIN              =$(addsuffix $(SRCS_EXT), $(BONUS_MAIN_NAME))
DEPS                    =$(addprefix $(DEPENDENCIES)/, $(DEPENDENCIES_PATHS))

ifeq ($(SRCS_DIR),)
SRCS            =$(SOURCES)
else
SRCS            =$(addprefix $(SRCS_DIR)/,$(SOURCES))
endif

ifeq ($(OBJS_DIR),)
OBJS            =$(patsubst %$(SRCS_EXT),%$(OBJS_EXT), $(SOURCES))
else
OBJS            =$(patsubst %$(SRCS_EXT),$(OBJS_DIR)/%$(OBJS_EXT), $(SOURCES))
endif

ifeq ($(OBJS_DIR),)
BOBJS            =$(patsubst %$(SRCS_EXT),%$(OBJS_EXT), $(SOURCES))
else
BOBJS            =$(patsubst %$(SRCS_EXT),$(OBJS_DIR)/%$(OBJS_EXT), $(SOURCES))
endif

ifeq ($(DFILES_DIR),)
DFS             =$(patsubst %$(SRCS_EXT),%$(DFILES_EXT), $(SOURCES))
else
DFS             =$(patsubst %$(SRCS_EXT),$(DFILES_DIR)/%$(DFILES_EXT), $(SOURCES))
endif

CADDLINK        =$(addprefix -L, $(dir $(DEPS)))

INCS            =$(addprefix -I, $(INCLUDES_DIR))

#*
#* ************************************************************************** *#
#*                              Directories Rule                              *#
#* ************************************************************************** *#
#*
%/:
	mkdir -p $@
#*
#* ************************************************************************** *#
#*                                Bonus Rule                                  *#
#* ************************************************************************** *#
#*
bonus:
	@make SOURCES="$(BONUS_SOURCES_NAME)" \
		MAIN="$(BONUS_MAIN_NAME)" \
		BONUS_MAIN="$(MAIN_NAME)" all
.PHONY:bonus
#*
#* ************************************************************************** *#
#*                               Objects Rule                                 *#
#* ************************************************************************** *#
#*
ifeq ($(OBJS_DIR),)
%$(OBJS_EXT): %$(SRCS_EXT)
	$(CC) $(CFLAG) $(INCS) -c $< -o $@ 
else

.SECONDEXPANSION:
$(OBJS_DIR)/%$(OBJS_EXT): $(SRCS_DIR)/%$(SRCS_EXT) | \
		$$(dir $$@) \
		$$(dir $$(DFILES_DIR)/$$*$$(DFILES_EXT))
	$(CC) $(CFLAG) $(INCS) -c $< -o $@ $(DFLAG)
endif

include $(wildcard $(DFS))
#*
#* ************************************************************************** *#
#*                            Dependencies rules                              *#
#* ************************************************************************** *#
#*
%.a:
	(cd $(dir $@) && make)
#*
#* ************************************************************************** *#
#*                             Compilation Rule                               *#
#* ************************************************************************** *#
ifneq ($(LIBRARY),)
$(NAME): $(OBJS)
	rm -f $(BONUS_MAIN)
	$(ARCHIVE) $(NAME) $(OBJS)
else
$(NAME): $(OBJS) $(DEPS)
	rm -f $(BONUS_MAIN)
	$(CC) $(CFLAG) -o $(NAME) $(OBJS) $(CADDLINK) $(CLINK)
endif
compile: $(NAME)
.PHONY: compile all
#*
#* ************************************************************************** *#
#*                                     Run                                    *#
#* ************************************************************************** *#
#*
ifeq ($(LIBRARY),)
run:
	./$(NAME) $(ARG)
debug_run:
	$(DEBUG_PROGRAM) $(DEBUG_NAME) $(ARG)
drun: debug_run

r: run

dr: drun
.PHONY: run debug_run drun r dr
endif
#*
#* ************************************************************************** *#
#*                                    Debug                                   *#
#* ************************************************************************** *#
#*
ifeq ($(LIBRARY),)
$(DEBUG_NAME): $(SRCS)
	rm -f $(BONUS_MAIN)
	$(CC) $(DEBUG_FLAG) $(INCS) -o $(DEBUG_NAME) $(SRCS) $(CADDLINK) $(CLINK)
debug: $(DEBUG_NAME)

de: debug

db: debug

.PHONY:de debug db
endif
#*
#* ************************************************************************** *#
#*                                    Cleanup                                 *#
#* ************************************************************************** *#
#*
CLEAN_FILES= $(wildcard $(sort $(OBJS) $(BOBJS) $(DFS)))
FCLEAN_FILES= $(wildcard $(NAME) $(DEBUG_NAME))

clean:
ifneq ($(CLEAN_FILES),)
	rm -f $(CLEAN_FILES)
endif

fclean: clean
ifneq ($(FCLEAN_FILES),)
	rm -f $(FCLEAN_FILES)
endif

re: fclean all

remake: re

test:
	@echo '$(SUBDIRECTORIES)'

.PHONY: clean fclean re remake
#*
#* ************************************************************************** *#
#*                                   Appendix                                 *#
#* ************************************************************************** *#
#*
