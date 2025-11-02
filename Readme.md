# Building the project 

```
mkdir -p build
cmake -S . -B build
cmake --build build
```

# Running all tests
```
cd build
cd bin 
./algorithms
```

# Running a specific test
```
cd build
cd bin
./algorithms --gtest_filter="LinkedListTests.*"
```

# Debugging with lldb

make sure to build the project in Debug mode:
```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

Then run lldb:
```
cd build
cd bin
lldb ./algorithms

// Not gonna work
run --gtest_filter="ContainsDuplicates.*

// do it with
process launch -- '--gtest_filter=ContainsDuplicates.*'
```

# TODO VSCODE Debugging
WIP: Currently not working


Nvim guide

Once you build the project compile_commands.json will be generated in the build folder. 
You can use this file to get code completion and other IDE features in Neovim 
using the `nvim-cmp` and `nvim-lspconfig` plugins.


