TARGET   = main

CC=g++
LL=g++

SRC=./src
OUT=./out

CFLAGS=  -O3 -ansi -g -Wno-unused-result 
LFLAGS=  -lmysqlclient -lpthread -lz -lm  -ldl

INC= -I/usr/include/mysql -I./inc -I/usr/local/include/mysql
#INC= -I/usr/local/Cellar/mysql/8.0.21/include/mysql -I./inc -I/usr/local/Cellar/mysql/8.0.21/include/mysql

SOURCES  := $(wildcard $(SRC)/*.cpp)
OBJECTS  := $(SOURCES:%.cpp=%.o)

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LL) $(OBJECTS) $(LFLAGS) -o ${TARGET}.o
	@mv ${SRC}/*.o ${OUT}
	@cp ${TARGET}.o ${OUT}
	@echo "Linking complete!"

$(OBJECTS): $(OBJ)%.o : %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@ ${INC}  $(mysql_config --cflags)
	@echo "[PH] "$<

all:$(BINDIR)/$(TARGET)

clean:
	@echo "Clean complete!"
	@rm -rf *.o *.out $(SRC)/*.o $(SRC)/*.out
	@rm -rf ${OUT}/*.o  *.o
  