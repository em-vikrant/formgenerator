# FORM GENERATOR

A C++ Library to create forms that uses SFML.

## DEVELOPMENT STATE

* It has two working branches  
&emsp;```main```  
&emsp;```dev```  
* **main** branch is stable. It can be used without any problem.
* All future changes first come in **dev** branch and later on it will get added to **main**

## REQUIREMENTS

Must have these:  
```cmake, make, SFML```

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
* Open CMakeLists.txt and modify accordingly to generate a debug or release build.
* Generator cmake build bundle
    * On Windows : MinGW compiler  
    ```cmake -G "MinGW Makefiles" -S . -B ./build```
    * On Mac / Linux  
    ```cmake -S . -B ./build```

### Build package compilation

* Invoke cmake to start compilation for the generated build package  
```cmake --build ./build```

## RUN

* Locate the application:- check example directory in build created after compilation.

