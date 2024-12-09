# Compiler settings
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
BUILD_DIR   = build

# Source files
TEST_SRCS   = $(wildcard test_*.c)      # All test files (e.g., test_isalpha.c)
LIB_SRCS    = $(wildcard ../ft_*.c)    # All library implementation files (e.g., ft_isalpha.c)
TEST_UTILS  = utils.c                  # Utility functions for tests
TEST_BINS   = $(patsubst %.c, $(BUILD_DIR)/%, $(TEST_SRCS)) # Test binaries

# Default target: Build all test binaries
all: $(BUILD_DIR) $(TEST_BINS)

# Create the build directory
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Rule to compile each test file into its own binary
$(BUILD_DIR)/%: %.c $(TEST_UTILS) $(LIB_SRCS)
	@$(CC) $(CFLAGS) -DMAIN -o $@ $< $(TEST_UTILS) $(LIB_SRCS)

# Rule to run all tests
run: all
	@for test_bin in $(TEST_BINS); do \
		if [ -x $$test_bin ]; then \
			echo "Running $$test_bin..."; \
			./$$test_bin || exit 1; \
		else \
			echo "Error: $$test_bin not found or not executable!"; \
			exit 1; \
		fi; \
	done

# Rule to run a specific test
run_%: $(BUILD_DIR)/%
	@echo "Running $*..."
	@./$(BUILD_DIR)/$* || exit 1
# Clean build artifacts
clean:
	@rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all run clean

