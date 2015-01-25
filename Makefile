rwildcard		=	$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2)\
					$(filter $(subst *,%,$2),$d))

NAME			=	libfts.a
OBJ_DIR			=	objs

LIB_NAME		=	fts
SRC_DIR			=	srcs
SRC				=	$(call rwildcard, $(SRC_DIR), *.s)
OBJ				=	$(addprefix $(OBJ_DIR)/, $(SRC:.s=.o))

TESTS_NAME		=	libfts_tests
TESTS_SRC_DIR	=	tests
TESTS_SRC		=	$(call rwildcard, $(TESTS_SRC_DIR), *.cpp)
TESTS_OBJ		=	$(addprefix $(OBJ_DIR)/, $(TESTS_SRC:.cpp=.o))

ASSEMBLER		=	nasm
COMPILER		=	g++
AFLAGS			=	-f macho64
CFLAGS			=	-Wall -Wextra -Werror -O3 -std=c++1y -c
LFLAGS			=	-L. -l$(LIB_NAME) -Wl,-no_pie

OBJ_SUB_DIRS	=	$(dir $(OBJ))
OBJ_SUB_DIRS	+=	$(dir $(TESTS_OBJ))

all:
	@$(MAKE) $(NAME)
	@$(MAKE) $(TESTS_NAME)

$(NAME): $(OBJ)
	@echo "linking archive $@"
	@ar rc $@ $^
	@ranlib $@

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@$(foreach dir, $(OBJ_SUB_DIRS), mkdir -p $(dir);)

$(OBJ_DIR)/%.o: %.s
	@echo "assembling $(notdir $<)"
	@$(ASSEMBLER) $(AFLAGS) $< -o $@

$(TESTS_NAME): $(NAME) $(TESTS_OBJ)
	@echo "linking $@"
	@$(COMPILER) $(LFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp
	@echo "compiling $(notdir $<)"
	@$(COMPILER) $(CFLAGS) $< -o $@

clean:
	@echo "cleaning objects"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "cleaning $(NAME)"
	@rm -f $(NAME)
	@echo "cleaning $(TESTS_NAME)"
	@rm -f $(TESTS_NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all
