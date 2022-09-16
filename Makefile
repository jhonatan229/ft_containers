NAME = ft_containers

#_________________________/\__________________________#

PATH_SRC = ./tests
PATH_TESTES = ./tests/my_tests
PATH_SRC_STL = ./tests/STL
PATH_SRC_INTRA = ./tests/intra_test

#_________________________/\__________________________#

CXXFLAGS += -g -Wall -Wextra -Werror -std=c++98 
CXX = c++
RM = rm -rf

#_________________________/\__________________________#

IFLAGS = -I ./containers -I ./includes -I ./iterators -I ./tests

#_________________________/\__________________________#

all: $(NAME)

PATH_OBJ = ./obj
PATH_OBJ_MY_TESTES = ./obj_my_testes
PATH_OBJ_STL_TESTES = ./obj_stl_testes
SRC = $(addprefix $(PATH_SRC)/, my_test.cpp) 
OBJ = $(patsubst $(PATH_SRC)/%.cpp, $(PATH_OBJ)/%.o, $(SRC)) 

SRC_MY_TESTES = $(addprefix $(PATH_TESTES)/, my_check_type_test.cpp my_iterator_test.cpp) 
OBJ_MY_TESTS = $(patsubst $(PATH_TESTES)/%.cpp, $(PATH_OBJ_MY_TESTES)/%.o, $(SRC_MY_TESTES))



$(NAME): $(OBJ) $(OBJ_MY_TESTS)
	$(CXX) $(CXXFLAGS) $(IFLAGS) $(OBJ) $(OBJ_MY_TESTS) -o $@
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|           $(NAME) Created            |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(PATH_OBJ)/%.o: $(PATH_SRC)/%.cpp
	@mkdir -p $(PATH_OBJ)
	$(CXX) $(CXXFLAGS) $(IFLAGS) -c $< -o $@

$(PATH_OBJ_MY_TESTES)/%.o: $(PATH_TESTES)/%.cpp
	@mkdir -p $(PATH_OBJ_MY_TESTES)
	$(CXX) $(CXXFLAGS) $(IFLAGS) -c $< -o $@

#_________________________/\__________________________#

# PATH_OBJ_STL = ./obj_stl
# SRC_STL = $(addprefix $(PATH_SRC_STL)/, original_map.cpp original_iterator_test.cpp original_vector_test.cpp)
# OBJ_STL = $(patsubst $(PATH_SRC_STL)/%.cpp, $(PATH_OBJ_STL)/%.o, $(SRC_STL))

# stl: $(OBJ_STL)
# 	make -C $(PATH_GTEST)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(IFLAGS) $(LFLAGS) $(OBJ_STL) -o $@
# 	@echo "\033[1;32m"
# 	@echo "/ ************************************ \\"
# 	@echo "|           $(STL) Created            |"
# 	@echo "\\ ************************************ /"
# 	@echo "\033[0m"

# $(PATH_OBJ_STL)/%.o: $(PATH_SRC_STL)/%.cpp
# 	@mkdir -p $(PATH_OBJ_STL)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(IFLAGS) -c $< -o $@

# #_________________________/\__________________________#

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

# PATH_OBJ_PARFORM = ./obj_perform
# SRC_PERFORM = $(addprefix $(PATH_SRC_PERFORM)/, performance_test.cpp)
# OBJ_PERFORM = $(patsubst $(PATH_SRC_PERFORM)/%.cpp, $(PATH_OBJ_PARFORM)/%.o, $(SRC_PERFORM))

# perform: $(OBJ_PERFORM)
# 	make -C $(PATH_GTEST)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(IFLAGS) $(LFLAGS) $(OBJ_PERFORM) -o $@
# 	@echo "\033[1;32m"
# 	@echo "/ ************************************ \\"
# 	@echo "|           $(NAME) Created            |"
# 	@echo "\\ ************************************ /"
# 	@echo "\033[0m"

# $(PATH_OBJ_PARFORM)/%.o: $(PATH_SRC_PERFORM)/%.cpp
# 	@mkdir -p $(PATH_OBJ_PARFORM)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(IFLAGS) -c $< -o $@

# #_________________________/\__________________________#

# PATH_OBJ_STL_PERFORM = ./obj_stl_perform
# SRC_STL_PERFORM = $(addprefix $(PATH_SRC_STL_PERFORM)/, performance_test.cpp)
# OBJ_STL_PERFORM = $(patsubst $(PATH_SRC_STL_PERFORM)/%.cpp, $(PATH_OBJ_STL_PERFORM)/%.o, $(SRC_STL_PERFORM))

# original_perform: $(OBJ_STL_PERFORM)
# 	make -C $(PATH_GTEST)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(IFLAGS) $(LFLAGS) $(OBJ_STL_PERFORM) -o $@
# 	@echo "\033[1;32m"
# 	@echo "/ ************************************ \\"
# 	@echo "|           $(STL) Created            |"
# 	@echo "\\ ************************************ /"
# 	@echo "\033[0m"

# $(PATH_OBJ_STL_PERFORM)/%.o: $(PATH_SRC_STL_PERFORM)/%.cpp
# 	@mkdir -p $(PATH_OBJ_STL_PERFORM)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(IFLAGS) -c $< -o $@

# #_________________________/\__________________________#

clean:
	$(RM) $(PATH_OBJ)
	@echo "\033[1;31m"
	@echo "/ ************************************ \\"
	@echo "|          Deleted .o files            |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

fclean: clean
	$(RM) $(NAME)
	@echo "\033[1;31m"
	@echo "/ ************************************ \\"
	@echo "|          Deleted executables         |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

#_________________________/\__________________________#

re: fclean all

.PHONY: all clean fclean re