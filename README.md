# FORM GENERATOR

A C++ Library to create forms that uses SFML.  
It's an experimental project using which an interactive UI for the forms can be made quickly and easily.

## DEVELOPMENT STATE

* It has two working branches  
&emsp;```main```  
&emsp;```dev```  
* **main** branch is stable. It can be used without any problem.
* All future changes first come in **dev** branch and later on they will get added to **main** branch.

## REQUIREMENTS

Must have these:  
```cmake```&ensp;```make```&ensp;```SFML```

* Necessary directory architecture buildup:  
  
    * Clone the **SFML** code from their codebase [SFML GitHub repo](https://github.com/SFML/SFML/tree/2.6.x).  
    * Checkout to ***2.6.x*** branch.  
    * Build and compile it (in both debug & release mode). Similar to steps of compilation below.  
    * Clone **formgenerator** outside of the **SFML** git repo.  
    * Directory structure will look like  
    &emsp;```/--```  
    &emsp;&emsp;```- SFML```  
    &emsp;&emsp;```- formgenerator```  

## COMPILATION

### Genrate cmake build package

* Goto dir **formgenerator**  
```cd formgenerator```
* Open CMakeLists.txt and modify if necessary, to generate a debug or release build.
* Generate build package using cmake:
    * On Windows (from CMD) : MinGW compiler  
    ```cmake -G "MinGW Makefiles" -S . -B ./build```
    * On Mac / Linux (from Terminal)  
    ```cmake -S . -B ./build```

### Build package compilation

* Invoke cmake to start compilation for the generated build package  
```cmake --build ./build```

## RUN

* Locate the application:- check examples directory in build created after the compilation.

