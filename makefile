# 编译器
CXX = g++
CXXFLAGS = -std=c++17 -Wno-parentheses
DEBUGFLAGS = -g -O0

# 目标可执行文件
TARGET = seulex

# 源文件
SRC = seulex.cpp global.cpp regular.cpp readfile.cpp nfa.cpp dfa.cpp

# 对应的对象文件
OBJ = $(SRC:.cpp=.o)

# 默认目标
all: $(TARGET)

# 生成可执行文件
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# 编译 .cpp 文件为 .o 文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理目标
clean:
	rm -f $(OBJ) $(TARGET)

# 运行程序
run: $(TARGET)
	@echo "Usage: make run FILE=xxx.l"
	@./$(TARGET) $(FILE)

minic: FILE = minic.l
minic: run


# debug 目标：附加调试标志，先清理再构建
debug: CXXFLAGS += $(DEBUGFLAGS)
debug: clean all

.PHONY: all clean run debug