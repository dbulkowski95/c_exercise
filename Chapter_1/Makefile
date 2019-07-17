THIS_DIR := $(PROJECT_DIR)/Chapter_1

IDIR := $(THIS_DIR)/inc
SDIR := $(THIS_DIR)/src
TDIR := $(THIS_DIR)/test
LDIR :=

SRCS := $(wildcard $(SDIR)/*.c)
SRCS += $(wildcard $(TDIR)/*.c)
OBJS := $(SRCS:%.c=%.o)

LIBS := -lcriterion

EXEC := $(THIS_DIR)/test.out

%.o: %.c
	$(call print_cc, $<)
	$(Q)$(CC) $(CFLAGS) -I$(IDIR) -c $< -o $@

$(EXEC): $(OBJS)
	$(call print_bin, $@)
	$(Q)$(CC) $(CFLAGS) -L$(LDIR) -I$(IDIR) $(OBJS) $(LIBS) -o $@

clean:
	$(call print_info,Cleaning)
	$(Q)$(RM) $(OBJS)
	$(Q)$(RM) $(EXEC)
