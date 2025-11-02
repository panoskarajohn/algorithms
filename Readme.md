# Building the project 

```
mkdir -p build
cmake -S . -B build
cmake --build build
```

Nvim guide

Once you build the project compile_commands.json will be generated in the build folder. 
You can use this file to get code completion and other IDE features in Neovim 
using the `nvim-cmp` and `nvim-lspconfig` plugins.


