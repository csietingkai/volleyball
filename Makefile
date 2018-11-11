CPP = g++
CPPFLAGS = -std=c++11 -c -g -Wall -DBOOST_LOG_DYN_LINK
LDFLAGS = -g
GTKMM_FLAG = `pkg-config gtkmm-3.0 --cflags --libs`
MYSQL_FLAG = -lmysqlcppconn
LBOOST_FLAG = -lboost_log 
LPTHR_FLAG = -lpthread
LBSYS_FLAG = -lboost_system

EXE = volleyball.exe
SRCDIR := ./src
TESTDIR := ./test
OBJDIR := ./obj
SRCS := $(wildcard $(SRCDIR)/*.cpp)
TESTS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS)) $(OBJDIR)/test.o $(OBJDIR)/main.o

all: $(EXE)

$(EXE): $(OBJS)
	$(CPP) $(LDFLAGS) -o $@ $^ $(MYSQL_FLAG) $(GTKMM_FLAG) $(LBOOST_FLAG) $(LPTHR_FLAG) $(LBSYS_FLAG)
	
$(OBJDIR)/main.o: ./main.cpp
	@mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) -o $@ $^ $(MYSQL_FLAG) $(GTKMM_FLAG) $(LBOOST_FLAG) $(LPTHR_FLAG) $(LBSYS_FLAG)

$(OBJDIR)/test.o: $(TESTDIR)/test.cpp
	@mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) -o $@ $^ $(MYSQL_FLAG) $(GTKMM_FLAG) $(LBOOST_FLAG) $(LPTHR_FLAG) $(LBSYS_FLAG)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) -o $@ $< $(MYSQL_FLAG) $(GTKMM_FLAG) $(LBOOST_FLAG) $(LPTHR_FLAG) $(LBSYS_FLAG)

clean:
	rm -rf $(OBJDIR)/*.o $(EXE) 
