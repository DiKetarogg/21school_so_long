# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 04:30:43 by jzoltan           #+#    #+#              #
#    Updated: 2022/03/29 15:51:50 by jzoltan          ###   ########.fr        #
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
LIBRARY         =
HAS_BONUS       = False
#*
#* ************************************************************************** *#
#*                             Executable name                                *#
#* ************************************************************************** *#
#*
NAME            = so_long
DEBUG_NAME      = deb_long
BONUS_NAME      = so_long
DEBUG_BONUS_NAME= deb_blong
#*
#* ************************************************************************** *#
#*                               Run Arguments                                *#
#* ************************************************************************** *#
#*
RUN=maps/test_bonus.ber
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
DFLAG                   =-MT $@ -MD -MP -MF $(DFILES_DIR)$*$(DFILES_EXT)
CLINK                   =-lmlx -lmlx -lXext -lX11 -lft -lftstring
DEPENDENCIES_PATHS      =minilibx-linux/libmlx.a ftstring/libftstring.a\
	ft/libft.a
#*
#* ************************************************************************** *#
#*                               Directories                                  *#
#* ************************************************************************** *#
#*
SRCS_DIR        =Sources/
INCLUDES_DIR    =Includes/ $(DEPENDENCIES)/minilibx-linux/ \
	$(DEPENDENCIES)/ftstring/Includes/ $(DEPENDENCIES)/ft/Includes/
OBJS_DIR        =Objects/
DFILES_DIR      =HeaderDependencies/
DEPENDENCIES    =Dependencies/
DEP_INCLUDES    =#ft/Includes/ jz/Includes/
#*
#* ************************************************************************** *#
#*                                  Files                                     *#
#* ************************************************************************** *#
#*
SOURCES_NAME            = so_long_handlers so_long_new so_long_loop \
	so_long_actions so_long_map_parser so_long_delete so_long_set_img_map \
	so_long_window so_oopi_mlx so_long_actions2 valid_arg so_long_init_map\


BONUS_SOURCES_NAME      = so_long_handlers so_long_new so_long_loop \
	so_long_actions so_long_map_parser_bonus so_long_delete_bonus so_long_set_img_map \
	so_long_window so_oopi_mlx so_long_actions2 valid_arg so_long_init_map_bonus\
	why_bonus
	

MAIN_NAME               =main

BONUS_MAIN_NAME         =main_bonus
#*
#* ************************************************************************** *#
#*                               Conversions                                  *#
#* ************************************************************************** *#
#*
SOURCES                 =$(addsuffix $(SRCS_EXT), $(SOURCES_NAME) $(MAIN_NAME))
BONUS_SOURCES           =$(addsuffix $(SRCS_EXT), $(BONUS_SOURCES_NAME) $(BONUS_MAIN_NAME))
DEPS                    =$(addprefix $(DEPENDENCIES), $(DEPENDENCIES_PATHS))

ifeq ($(SRCS_DIR),)
SRCS                    =$(SOURCES)
else
SRCS                    =$(addprefix $(SRCS_DIR),$(SOURCES))
endif

ifeq ($(SRCS_DIR),)
BSRCS                    =$(BONUS_SOURCES)
else
BSRCS                    =$(addprefix $(SRCS_DIR),$(BONUS_SOURCES))
endif

ifeq ($(OBJS_DIR),)
MAIN                    =$(patsubst %,%$(OBJS_EXT), $(MAIN_NAME))
else
MAIN                    =$(patsubst %,$(OBJS_DIR)%$(OBJS_EXT), $(MAIN_NAME))
endif

ifeq ($(OBJS_DIR),)
BONUS_MAIN              =$(patsubst %,%$(OBJS_EXT), $(BONUS_MAIN_NAME))
else
BONUS_MAIN              =$(patsubst %,$(OBJS_DIR)%$(OBJS_EXT), $(BONUS_MAIN_NAME))
endif

ifeq ($(OBJS_DIR),)
OBJS                    =$(patsubst %$(SRCS_EXT),%$(OBJS_EXT), $(SOURCES))
else
OBJS                    =$(patsubst %$(SRCS_EXT),$(OBJS_DIR)%$(OBJS_EXT), $(SOURCES))
endif

ifeq ($(OBJS_DIR),)
BOBJS                   =$(patsubst %$(SRCS_EXT),%$(OBJS_EXT), $(BONUS_SOURCES))
else
BOBJS                   =$(patsubst %$(SRCS_EXT),$(OBJS_DIR)%$(OBJS_EXT), $(BONUS_SOURCES))
endif

ifeq ($(DFILES_DIR),)
DFS                     =$(patsubst %$(SRCS_EXT),%$(DFILES_EXT), $(SOURCES))
else
DFS                     =$(patsubst %$(SRCS_EXT),$(DFILES_DIR)%$(DFILES_EXT), $(SOURCES))
endif

ifeq ($(DFILES_DIR),)
BDFS                     =$(patsubst %$(SRCS_EXT),%$(DFILES_EXT), $(BONUS_SOURCES))
else
BDFS                     =$(patsubst %$(SRCS_EXT),$(DFILES_DIR)%$(DFILES_EXT), $(BONUS_SOURCES))
endif

CADDLINK                =$(addprefix -L, $(dir $(DEPS)))

INCS                    =$(addprefix -I, $(INCLUDES_DIR) $(addprefix $(DEPENDENCIES), $(DEP_INCLUDES)))

#*
#* ************************************************************************** *#
#*                             Directories Rules                              *#
#* ************************************************************************** *#
#*
%/:
	mkdir -p $@
dirs: | $(SRCS_DIR) $(INCLUDES_DIR) $(OBJS_DIR) $(DFILES_DIR) $(DEPENDENCIES)
.PHONY: dirs
#*
#* ************************************************************************** *#
#*                                Bonus Rule                                  *#
#* ************************************************************************** *#
#*
ifneq ($(HAS_BONUS),)
ifeq ($(BONUS_NAME),$(NAME))

bonus:
	@make NAME="$(BONUS_NAME)"\
		OBJS="$(BOBJS)" \
		MAIN="$(BONUS_MAIN)" \
		BONUS_MAIN="$(MAIN)" \
		CLINK="$(CLINK) -pthread" all
else

$(BONUS_NAME): $(BOBJS) $(DEPS)
ifneq ($(wildcard $(BONUS_MAIN)),)
	rm -f $(BONUS_MAIN:%$(SRCS_EXT)=%$(OBJS_EXT))
endif
	$(CC) $(CFLAG) -o $(NAME) $(BOBJS) $(CADDLINK) $(CLINK)
.PHONY:bonus
endif
endif
#*
#* ************************************************************************** *#
#*                               Objects Rule                                 *#
#* ************************************************************************** *#
#*
.SECONDEXPANSION:
$(OBJS_DIR)%$(OBJS_EXT): $(SRCS_DIR)%$(SRCS_EXT) | \
		$$(dir $$@) \
		$$(dir $$(DFILES_DIR)$$*$$(DFILES_EXT))
	$(CC) $(CFLAG) $(INCS) -c $< -o $@ $(DFLAG)

include $(wildcard $(DFS))
#*
#* ************************************************************************** *#
#*                            Dependencies rules                              *#
#* ************************************************************************** *#
#*
%.a:
	$(MAKE) -C $(dir $@) all
#.PHONY: $(DEPS)
#*
#* ************************************************************************** *#
#*                             Compilation Rule                               *#
#* ************************************************************************** *#
ifneq ($(LIBRARY),)
$(NAME): $(OBJS) $(DEPS)
ifneq ($(wildcard $(BONUS_MAIN)),)
	rm -f $(BONUS_MAIN)
endif
	$(ARCHIVE) $(NAME) $(OBJS)
else
$(NAME): $(OBJS) $(DEPS)
ifneq ($(wildcard $(BONUS_MAIN)),)
	rm -f $(BONUS_MAIN)
endif
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
run: $(NAME)
	./$(NAME) $(RUN)

brun: bonus
	./$(NAME) $(RUN)
debug_run: $(DEBUG_NAME)
	$(DEBUG_PROGRAM) $(DEBUG_NAME) $(RUN)
drun: debug_run

debbrun: $(DEBUG_BONUS_NAME)
	$(DEBUG_PROGRAM) $(DEBUG_BONUS_NAME) $(RUN)

r: run

dr: drun
.PHONY: run debug_run drun r dr brun debrun
endif
#*
#* ************************************************************************** *#
#*                                    Debug                                   *#
#* ************************************************************************** *#
#*
ifeq ($(LIBRARY),)
$(DEBUG_NAME): $(SRCS) $(DEPS)
	rm -f $(BONUS_MAIN)
	$(CC) $(DEBUG_FLAG) $(INCS) -o $(DEBUG_NAME) $(SRCS) $(CADDLINK) $(CLINK)

$(DEBUG_BONUS_NAME): $(BSRCS) $(DEPS)
	rm -f $(BONUS_MAIN)
	$(CC) $(DEBUG_FLAG) $(INCS) -o $(DEBUG_BONUS_NAME) $(BSRCS) $(CADDLINK) $(CLINK) -pthread
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
CLEAN_FILES= $(wildcard $(sort $(OBJS) $(BOBJS) $(DFS) $(BDFS)))
FCLEAN_FILES= $(wildcard $(NAME) $(DEBUG_NAME) $(DEBUG_BONUS_NAME))

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

.PHONY: clean fclean re remake
#*
#* ************************************************************************** *#
#*                                   Appendix                                 *#
#* ************************************************************************** *#
#*
