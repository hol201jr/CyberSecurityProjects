# the compiler: gcc for C program, define as g++ for C++  
CC = g++   
# compiler flags:  
#  -g     - this flag adds debugging information to the executable file  
#  -Wall  - this flag is used to turn on most compiler warnings  
CFLAGS  = -g -Wall  
SOURCE = project2_encryption.cpp 
# The build target  
TARGET = project2_encryption
all: $(TARGET)   
$(TARGET): $(SOURCE)           
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)  
clean:              
	rm $(TARGET)