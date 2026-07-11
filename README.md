# DynamicArraySpellbook

**DynamicArraySpellbook** is a C library that makes dynamic arrays much easier to use and manage. Instead of
raw pointers and manually keeping track of size, and allocating memory, this library does all of that for you,
and you can focus on the more important aspects of your program.

## Clone the repository

```
git clone https://github.com/loganjellis/DynamicArraySpellbook.git
cd DynamicArraySpellbook
```

## Building

```
cmake -S . -B build
cmake --build build
```

### Using the library (in-directory, just place dynamic_array_spellbook.h inside your /include directory)

```
target_include_directories(app PRIVATE "path/to/include")
```

### Using the library (subdirectory)

```
add_subdirectory(DynamicArraySpellbook)
target_link_libraries(app PRIVATE DynamicArraySpellbook::dynamic_array_spellbook)
```

For an example of using the library, refer to `example.c`

To view the library's documentation, click <a href="docs/html" target="_blank">here</a>.
