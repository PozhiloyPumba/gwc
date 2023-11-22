# GWC project

## About it
It my realization [Lloyd's algorithm](https://en.wikipedia.org/wiki/Lloyd%27s_algorithm) with simply graphic header (api written with OpenGL)

In [this](./cppSample/fakeMain.cpp) file you can see realization of Lloyd's algorithm in c and draw it on screen (for now иупшт points fixed and located [here](./cppSample/src.h) with color for each)

## How build and run
### Build
```
$ git clone --recurse-submodules https://github.com/PozhiloyPumba/gwc.git
$ cd gwc
$ cmake -B build && cd build
$ cmake --build .
```
### Run cpp sample
```
$ cmake --build . --target run
```
## Instrumentation

Tested with llvm-14 Idk how it works with other versions(... 

If you want see how many each instruction was call for [this file](cppSample/fakeMain.cpp) you can see it [here](llvmInstrumentalPass/profiling) or run it by yourself (it may take a long time) with (it will generate dump.txt at your build directory):
```
$ cmake --build . --target run_instr
```
Or you can run graphic representation of this with (it will generate dump.txt at build directory if you didn't do it yet or using already exists after running **run_instr** target, but you must have python3 for this and matplotlib.): 
```
$ cmake --build . --target show_instr
```
Also you can run this app with in llvm simulator with (src in IR_gen directory): 
```
$ cmake --build . --target run_simulator
```
## Run llvm interpretator on generated IR on [this file](cppSample/fakeMain.cpp) from scratch

Sources [here](IR_gen/IR_generator.cpp)
```
$ cmake --build . --target run_IR_from_scratch
```
## Run my asm

[ISA](asm_IR/isa.yml) and [asm file](asm_IR/main.asm) (rewrited [this](cppSample/fakeMain.cpp)) pass to [this file](asm_IR/main.cpp) and depends on define ASM_RUN (if defined run my interpretator of instrs and IR generated of each instr if not defined)
For run my interpreter run:
```
$ cmake --build . --target run_asm
```
For run interpreter on generated IR:
```
$ cmake --build . --target run_asm_to_IR
```
## Some info about name

<table border="0"><tr>
    <td style="border-style: hidden;"> <img src="pics/name_explanation.jpg" height="250" title="some funny picture was here((("> </td>
    <td style="border-style: hidden;"> <img src="pics/calendar.jpg" height="250" title="some funny picture was here((("> </td>
</tr></table>


This repo was create for working with llvm. If we write LLVM (in upper case) we get Roman numbers let's add all of them.
$$L + L + V + M = 50 + 50 + 5 + 1000 = 1105$$
1105 is green wooden cock's (**GWC**) year in chinese calendar. Don’t try to understand how I got to these current ideas.

I'm not crazy (at least I hope)...
