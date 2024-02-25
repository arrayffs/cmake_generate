## cmake generate
___
This app solves the annoying process of having to write a CMakeLists.txt file every time you want to make a medium-ish sized app and can't use GCC to easily compile, you can either download the compiled binary from the releases or you can look at the build guide in the readme.
___
### dependencies
-  CMake
-  Make

i'm assuming you are smart enough to install those yourselves :3
___
### usage

please note that the directory you are supplying has to already exist, this will not create the directory itself.

``` bash
# this will generate the files inside the CWD
$ cmake_generate "."

# you can pass it a relative address, this will create the file in the cool/ directory
$ cmake_generate "cool/"

# if you don't want to do that or its messing up you can pass it a full path aswell of course
$ cmake_generate "/home/user/projects/cool/"
```
___
### building
#### one liner
```
git clone https://github.com/arrayffs/cmake_generate && cd cmake_generate/scripts && ./compile
```
#### step by step
step 1: clone the directory
``` bash
git clone https://github.com/arrayffs/cmake_generate
```

step 2: cd into the scripts directory
``` bash
cd cmake_generate/scripts/
```

step 3: give the compiler script run permissions
``` bash
chmod +x compiler
```

step 4: run the compiler script
``` bash
./compiler
```

the executable will be placed into the build/ folder which is one directory higher than the scripts/ folder
