CPP = g++
CPPFLAGS = -std=c++11 -c -g -Wall
LDFLAGS = -g
UUID_FLAG = -luuid
GTKMM_FLAG = `pkg-config gtkmm-3.0 --cflags --libs`

EXE = test
SRCDIR := ./src
OBJDIR := ./obj
SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS)) $(OBJDIR)/main.o

all: $(EXE)

$(EXE): $(OBJS)
	$(CPP) $(LDFLAGS) -o $@ $^ $(UUID_FLAG) $(GTKMM_FLAG)
	
$(OBJDIR)/main.o: ./main.cpp
	$(CPP) $(CPPFLAGS) -o $@ $^ $(UUID_FLAG) $(GTKMM_FLAG)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $< $(UUID_FLAG) $(GTKMM_FLAG)

clean:
	rm -rf $(OBJDIR)/*.o $(EXE) 
