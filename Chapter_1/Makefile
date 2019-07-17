THIS_DIR := $(PROJECT_DIR)/Chapter_1

IDIR := $(THIS_DIR)/inc
SDIR := $(THIS_DIR)/src
TDIR := $(THIS_DIR)/test
LDIR :=

SRCS := $(wildcard $(SDIR)/*.c)
OBJS := $(SRCS:%.c=%.o)
DEPS := $(wildcard $(IDIR)/*.h)+
DEPS += $(wildcard $(EIDIR)/*.h)

LIBS := -lcriterion

EXEC := $(THIS_DIR)/add.out

#.PHONY:clean
#test: FORCE
#$(CC) -DTEST_MODE $(DIR_SRC)/*.c $(DIR_TEST)/*.c -I$(DIR_INC) -o $(TEXEC)

%.o: %.c
	$(call print_cc, $<)
	$(Q)$(CC) $(CFLAGS) -I$(IDIR) -c $< -o $@

$(EXEC): $(OBJS)
	$(call print_bin, $@)
	$(Q)$(CC) $(CFLAGS) -L$(LDIR) -I$(IDIR) $(OBJS) $(LIBS) -o $@

clean:
	$(call print_info,Cleaning)
	$(Q)$(RM) $(OBJS)
	$(Q)$(RM) $(T_OBJS)
	$(Q)$(RM) $(EXEC)
	$(Q)$(RM) $(T_EXEC)