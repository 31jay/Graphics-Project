## Language: 
C++, Compiler: MinGW 

## Library: 
graphics.h and other default c++ libraries 
### graphics.h Setup:
* download the graphics.h, libbgi.a and winbgim.h
* inside MinGW>>include>> add graphics.h and winbgim.h
* inside MinGW>>lib>> add libbgi.a
* Add the linker: -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
* In codeblocks: Settings>> Compiler>> Linker Settings>> other link options: add the linker
