# macros
CXX = g++
#CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -pedantic-errors

# files
src = src
obj = src/obj
exec = RPGgame.exe

$(obj)/%.o : $(src)/%.cpp
	mkdir -p $(obj)
	$(CXX) $(CXXFLAGS) $< -c -o $@

$(exec) : $(obj)/main.o $(obj)/enemy.o $(obj)/hero.o $(obj)/item.o $(obj)/weapon.o $(obj)/armor.o
	$(CXX) $(CXXFLAGS) $^ -o $@

all :
	$(CXX) $(CXXFLAGS) $(src)/main.cpp $(src)/enemy.cpp $(src)/hero.cpp $(src)/item.cpp $(src)/weapon.cpp $(src)/armor.cpp -o $(exec)

test : $(exec)
	./$(exec)

clean : 
	rm -rf $(obj)
	rm -rd $(exec)