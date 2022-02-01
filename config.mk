# ======= BUILD CONFIG ======= #

# --- COMPILER --- #

CC = clang

# --- LINKER --- #

LD = clang

# --- DEPENDENCY GENERATOR --- #

MM = clang

# --- COMPILER FLAGS --- #

CCFLAGS += -std=c17
CCFLAGS += -Wall
CCFLAGS += -Wpedantic

# --- LINKER FLAGS --- #

LDFLAGS += -std=c17

# --- LINKER LIBRARIES --- #

LDLIBS +=

# --- ARTIFACTS FOLDER --- #

ART = bin

# --- BINARY EXECUTABLE NAME --- #

EXE = list

# --- SOURCE FILE DIRECTORIES --- #

DIR +=

# ============================ #
