# Description
A small project to explore Raylib and The C programming language



## How to setup 
- ```mkdir build && cd build ```
- ``` cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 .. ``` This will generate a file called ```compile_commands.json```  that is needed for clangd ( For LSP goodies when using nvim ) if you are using something else you can probably omit this and just run ``` cmake .. ```   
- Go back in root dir and run ```  make -C build ```
