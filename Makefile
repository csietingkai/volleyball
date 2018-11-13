CPP = g++
CPPFLAGS = -std=c++11 -c -g -Wall -DBOOST_LOG_DYN_LINK -lpthread
LDFLAGS = -g
GTKMM_FLAG = `pkg-config gtkmm-3.0 --cflags --libs`
MYSQL_FLAG = -lmysqlcppconn
BOOST_LOG_FLAG = -lboost_log -lboost_system -lboost_thread -lboost_log_setup

EXE = volleyball.exe
SRCDIR := ./src
TESTDIR := ./test
OBJDIR := ./obj
SRCS := $(wildcard $(SRCDIR)/*.cpp)
TESTS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS)) $(OBJDIR)/test.o $(OBJDIR)/main.o

all: $(EXE)

$(EXE): $(OBJS)
	$(CPP) $(LDFLAGS) -o $@ $^ $(MYSQL_FLAG) $(GTKMM_FLAG) $(BOOST_LOG_FLAG)
	
$(OBJDIR)/main.o: ./main.cpp
	@mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) -o $@ $^ $(MYSQL_FLAG) $(GTKMM_FLAG) $(BOOST_LOG_FLAG)

$(OBJDIR)/test.o: $(TESTDIR)/test.cpp
	@mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) -o $@ $^ $(MYSQL_FLAG) $(GTKMM_FLAG) $(BOOST_LOG_FLAG)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) -o $@ $< $(MYSQL_FLAG) $(GTKMM_FLAG) $(BOOST_LOG_FLAG)

clean:
	rm -rf $(OBJDIR)/*.o $(EXE) *.log
