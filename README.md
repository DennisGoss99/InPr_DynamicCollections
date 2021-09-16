# Data Containers in C
As we have a need to store data, there is a need for containers.
Storeing this data can be a hassle, so we created a few solutions in the C-Programming language.

Every modern language today has some sort of generic type, often marked as T for Type.
Then we have the C language. Classic-Old C does not have this feature but it was in a way added in C11.

So how can we still use a gerneric list in older versions of C?
Thats what this project is about.

## Basic Containers
Basic containers are often integrated into the language as they get used alot.
- Stack
- Queue
- List
- LinkedList
- Dictionary

## Gerneral Containers
Then we have more general containers that have more specific uses. Still they are often integrated into languages.
- String
- NumberLists
- ...

# Additional Tests
Ofcorse we need to test if our containers work properly.
To do that, we used them thoroughly, watching closely if they behave as expected.

# Compiling
## Tested Systems
The code was written in Visual Studio under Windows 10 compiled for x86 and x64.

Additionally it was tested under Linux Mint & Ubuntu for x86 and x64.
This required an extra makefile creation. This file is directly besides the VisualStudio project file.

## How to compile
### Windows
Open this project in Visual Studio and select the Test-Project as 'Start-Project'. Without this change it may want to start an .lib file, that will result in an error.

### Linux
Navigate to the MakeFile. There is a script that can be used for compiling. it creates a bin folder for temporal files, then compiles and starts the finished file afterwarts.

Remember to make it 'executable' with
chmod +x FileName.sh
Then to open
./FileName.sh
 
