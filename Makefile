CPP = g++
CPPFLAGS = -std=c++11 -c -g -Wall -DBOOST_LOG_DYN_LINK -lpthread
LDFLAGS = -g
GTKMM_FLAG = `pkg-config gtkmm-3.0 --cflags --libs`
MYSQL_FLAG = -lmysqlcppconn
BOOST_LOG_FLAG = -lboost_log -lboost_system -lboost_thread -lboost_log_setup -lboost_regex

EXE = volleyball.exe
SRCDIR := ./src
OBJDIR := ./obj
LOGDIR := ./logs
SRCS := $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(SRCDIR)/**/*.cpp) $(wildcard $(SRCDIR)/**/**/*.cpp)
OBJS := $(OBJDIR)/main.o $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

all: $(EXE)

$(EXE): $(OBJS)
	$(CPP) $(LDFLAGS) -o $@ $^ $(MYSQL_FLAG) $(GTKMM_FLAG) $(BOOST_LOG_FLAG)
	
$(OBJDIR)/main.o: ./main.cpp
	@mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) -o $@ $^ $(MYSQL_FLAG) $(GTKMM_FLAG) $(BOOST_LOG_FLAG)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) -o $@ $< $(MYSQL_FLAG) $(GTKMM_FLAG) $(BOOST_LOG_FLAG)

clear:
	rm -rf $(OBJDIR)/* $(EXE) 

clean:
	rm -rf $(OBJDIR)/* $(LOGDIR)/*.log $(EXE) 
