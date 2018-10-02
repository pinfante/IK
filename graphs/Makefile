EXE = Tests

SRC_DIR = src
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CPP = g++
LIBS = $(LIB_PATH)/libgtest.a $(LIB_PATH)/libgtest_main.a
CPPFLAGS = -Iinclude -Wall -g3 -D DEBUG -std=c++17
LDFLAGS =  -lgtest -lgtest_main -L/usr/lib -lpthread -lrt

all: $(EXE)

$(EXE) : $(OBJ)
	$(CPP) $(LDFLAGS) $^ $(LDFLAGS) $(LIBS) -o $@
	./Tests

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) Tests 
