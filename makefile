# macros
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -pedantic-errors

# files
src = src
obj = src/obj
exec = RPGgame

$(obj)/%.o : $(src)/%.cpp
	mkdir -p $(obj)
	$(CXX) $(CXXFLAGS) $< -c -o $@

all :
	$(CXX) $(CXXFLAGS) main.cpp enemy.cpp hero.cpp item.cpp weapon.cpp armor.cpp -o $(exec)

test : $(exec)
	./$(exec)