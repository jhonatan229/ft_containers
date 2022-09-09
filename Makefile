NAME = ft_containers
STL = stl_containers

#_________________________/\__________________________#

PATH_SRC = ./tests/my_tests
PATH_SRC_STL = ./tests/STL
PATH_SRC_INTRA = ./tests/intra_test
PATH_GTEST = ./tests
GTEST_DIR = ./tests/googletest/googletest

#_________________________/\__________________________#

CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -g -Wall -Wextra -Werror -pthread -fsanitize=address
CXX = c++
RM = rm -rf

#_________________________/\__________________________#

IFLAGS = -I ./containers -I ./includes -I ./iterators
LFLAGS = $(PATH_GTEST)/gtest_main.a -lpthread

#_________________________/\__________________________#

all: $(NAME)

PATH_OBJ = ./obj
SRC = $(addprefix $(PATH_SRC)/, my_check_type_test.cpp my_iterator_test.cpp my_map_test.cpp my_vector_test.cpp my_stack_test.cpp)
OBJ = $(patsubst $(PATH_SRC)/%.cpp, $(PATH_OBJ)/%.o, $(SRC))

$(NAME): $(OBJ)
	make -C $(PATH_GTEST)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(IFLAGS) $(LFLAGS) $(OBJ) -o $@
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|           $(NAME) Created            |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(PATH_OBJ)/%.o: $(PATH_SRC)/%.cpp
	@mkdir -p $(PATH_OBJ)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(IFLAGS) -c $< -o $@

#_________________________/\__________________________#

PATH_OBJ_STL = ./obj_stl
SRC_STL = $(addprefix $(PATH_SRC_STL)/, original_map.cpp original_iterator_test.cpp original_vector_test.cpp)
OBJ_STL = $(patsubst $(PATH_SRC_STL)/%.cpp, $(PATH_OBJ_STL)/%.o, $(SRC_STL))

stl: $(OBJ_STL)
	make -C $(PATH_GTEST)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(IFLAGS) $(LFLAGS) $(OBJ_STL) -o $@
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|           $(STL) Created            |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(PATH_OBJ_STL)/%.o: $(PATH_SRC_STL)/%.cpp
	@mkdir -p $(PATH_OBJ_STL)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(IFLAGS) -c $< -o $@

#_________________________/\__________________________#

PATH_OBJ_INTRA = ./obj_intra
SRC_INTRA = $(addprefix $(PATH_SRC_INTRA)/, intra_test.cpp)
OBJ_INTRA = $(patsubst $(PATH_SRC_INTRA)/%.cpp, $(PATH_OBJ_INTRA)/%.o, $(SRC_INTRA))

intra: $(OBJ_INTRA)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(IFLAGS) $(OBJ_INTRA) -o $@
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|           $(INTRA) Created            |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(PATH_OBJ_INTRA)/%.o: $(PATH_SRC_INTRA)/%.cpp
	@mkdir -p $(PATH_OBJ_INTRA)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(IFLAGS) -c $< -o $@


#_________________________/\__________________________#

PATH_OBJ = ./obj
SRC = $(addprefix $(PATH_SRC)/, performance_test.cpp)
OBJ = $(patsubst $(PATH_SRC)/%.cpp, $(PATH_OBJ)/%.o, $(SRC))

perform: $(OBJ)
	make -C $(PATH_GTEST)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(IFLAGS) $(LFLAGS) $(OBJ) -o $@
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|           $(NAME) Created            |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(PATH_OBJ)/%.o: $(PATH_SRC)/%.cpp
	@mkdir -p $(PATH_OBJ)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(IFLAGS) -c $< -o $@

#_________________________/\__________________________#

PATH_OBJ_STL = ./obj_stl
SRC_STL = $(addprefix $(PATH_SRC_STL)/, performance_test.cpp)
OBJ_STL = $(patsubst $(PATH_SRC_STL)/%.cpp, $(PATH_OBJ_STL)/%.o, $(SRC_STL))

original_perform: $(OBJ_STL)
	make -C $(PATH_GTEST)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(IFLAGS) $(LFLAGS) $(OBJ_STL) -o $@
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|           $(STL) Created            |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(PATH_OBJ_STL)/%.o: $(PATH_SRC_STL)/%.cpp
	@mkdir -p $(PATH_OBJ_STL)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(IFLAGS) -c $< -o $@

#_________________________/\__________________________#

clean:
	make clean -C $(PATH_GTEST)
	$(RM) $(PATH_OBJ)
	@echo "\033[1;31m"
	@echo "/ ************************************ \\"
	@echo "|          Deleted .o files            |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

fclean: clean
	make fclean -C $(PATH_GTEST)
	$(RM) $(NAME)
	@echo "\033[1;31m"
	@echo "/ ************************************ \\"
	@echo "|          Deleted executables         |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

#_________________________/\__________________________#

re: fclean all

.PHONY: all clean fclean re