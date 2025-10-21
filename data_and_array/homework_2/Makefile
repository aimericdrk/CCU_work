##
## CCU PROJECT, 2025
## Data Stucture, homework 1, problem 2
## File description:
## Makefile
##


EX_1_SRC_FILES =	  		print_help.c     		 \
        					IO_interactions.c    	 \
							queue_operations.c       \
        					find_shortest_path.c

EX_2_SRC_FILES =		    hanoi.c 			\
        					print_help.c        \
        					print_infos.c       \
							rod_name.c       	\
							stack_operations.c



EX_1_INC =		problem_1

EX_1_NAME =  	$(EX_1_INC)/problem_one.c

EX_1_BIN =		problem_one

EX_2_INC =		problem_2

EX_2_NAME	=	$(EX_2_INC)/problem_two.c

EX_2_BIN	=	problem_two

RULE = gcc

CFLAGS = -Wall -Wextra -Werror

CSRCFLAGS = $(CFLAGS)

BINFLAGS =  $(CFLAGS)

EX_1_SRC =	$(EX_1_SRC_FILES:%=problem_1/src/%)

EX_1_OBJ = $(EX_1_SRC:%.c=%.o)

EX_1_TESTS = problem_1/tests/tester.sh

EX_2_SRC = $(EX_2_SRC_FILES:%=problem_2/src/%)

EX_2_OBJ = $(EX_2_SRC:%.c=%.o)

EX_2_TESTS = problem_2/tests/tester.sh

all: $(EX_2_BIN) $(EX_1_BIN)

$(EX_2_BIN): $(EX_2_OBJ)
	@compilation_status=0; \
	command_to_execute="$(RULE) -o $(EX_2_BIN) $(EX_2_NAME) \
		$(EX_2_OBJ) $(BINFLAGS) -I./$(EX_2_INC)"; \
	echo -e "\033[0;34m$$command_to_execute\033[0m"; \
	$$command_to_execute; \
	if [ $$? -eq 0 ]; then \
		echo -e "\033[0;32mCompilation of $(EX_2_BIN)" \
		"successful!\033[0m"; \
	else \
		echo -e "\033[0;31mCompilation of $(EX_2_BIN)" \
		"failed!\033[0m"; \
		compilation_status=1; \
	fi; \
	exit $$compilation_status

$(EX_1_BIN): $(EX_1_OBJ)
	@compilation_status=0; \
	command_to_execute="$(RULE) -o $(EX_1_BIN) $(EX_1_NAME) \
		$(EX_1_OBJ) $(BINFLAGS)  -I./$(EX_1_INC)"; \
	echo -e "\033[0;34m$$command_to_execute\033[0m"; \
	$$command_to_execute; \
	if [ $$? -eq 0 ]; then \
		echo -e "\033[0;32mCompilation of $(EX_1_BIN)" \
		"successful!\033[0m"; \
	else \
		echo -e "\033[0;31mCompilation of $(EX_1_BIN)" \
		"failed!\033[0m"; \
		compilation_status=1; \
	fi; \
	echo -e ""; \
	if [ $$compilation_status -eq 1 ]; then \
		echo -e "\033[0;31m-------- Compilation failed! --------\033[0m"; \
		exit 1; \
	else \
		echo -e "\033[0;32m-------- Compilation successful! --------\033[0m"; \
	fi; \
	exit $$compilation_status

$(EX_1_OBJ): %.o: %.c
	@command_to_execute="$(RULE) -c $< -o $@ $(CSRCFLAGS) -I./$(EX_1_INC)"; \
	compilation_status=0; \
	echo -e "\033[0;34m$$command_to_execute\033[0m"; \
	$$command_to_execute; \
	if [ $$? -eq 0 ]; then \
		echo -e "\033[0;32mCompilation of $< successful!\033[0m"; \
	else \
		echo -e "\033[0;31mCompilation of $< failed!\033[0m"; \
		compilation_status=1; \
	fi; \
	echo -e ""; \
	exit $$compilation_status

$(EX_2_OBJ): %.o: %.c
	@command_to_execute="$(RULE) -c $< -o $@ $(CSRCFLAGS) -I./$(EX_2_INC)"; \
	compilation_status=0; \
	echo -e "\033[0;34m$$command_to_execute\033[0m"; \
	$$command_to_execute; \
	if [ $$? -eq 0 ]; then \
		echo -e "\033[0;32mCompilation of $< successful!\033[0m"; \
	else \
		echo -e "\033[0;31mCompilation of $< failed!\033[0m"; \
	fi; \
	echo -e ""; \
	exit $$compilation_status

clean:
	@command_to_execute="rm -f $(EX_1_OBJ) $(EX_2_OBJ)"; \
	echo -e "\033[0;34m$$command_to_execute\033[0m"; \
	$$command_to_execute; \
	if [ $$? -eq 0 ]; then \
		echo -e "\033[0;32mClean successful!\033[0m"; \
	else \
		echo -e "\033[0;31mClean failed!\033[0m"; \
	fi
	@echo -e ""

fclean: clean
	@command_to_execute="rm -rf $(EX_2_BIN) $(EX_1_BIN)"; \
	echo -e "\033[0;34m$$command_to_execute\033[0m"; \
	$$command_to_execute; \
	if [ $$? -eq 0 ]; then \
		echo -e "\033[0;32mFclean successful!\033[0m"; \
	else \
		echo -e "\033[0;31mFclean failed!\033[0m"; \
	fi; \
	echo -e ""

re: fclean all
	@if [ $$? -eq 0 ]; then \
		echo -e "\033[0;32m-------- Rebuild successful! --------\033[0m"; \
	else \
		echo -e "\033[0;31m-------- Rebuild failed! --------\033[0m"; \
	fi


test_ex_1:
	@chmod +x $(EX_1_TESTS)
	@$(EX_1_TESTS)

test_ex_2:
	@chmod +x $(EX_2_TESTS)
	@$(EX_2_TESTS)

ftests:
	@${EX_1_TESTS}
	@${EX_2_TESTS}

