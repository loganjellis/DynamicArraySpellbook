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

## Optionally installing

```
cmake --install build --prefix ./install
```

> [!NOTE]
> Note that ./install is a placeholder install location for the library. Omitting the install location results in the library being installed in the operating system's default path.

### Using the library (installed package)

```
list(APPEND CMAKE_PREFIX_PATH "/path/to/dynamic_array_spellbook/install")
find_package(DynamicArraySpellbook REQUIRED)
target_link_libraries(app PRIVATE DynamicArraySpellbook::dynamic_array_spellbook)
```

### Using the library (subdirectory)

```
add_subdirectory(DynamicArraySpellbook)
target_link_libraries(app PRIVATE DynamicArraySpellbook::dynamic_array_spellbook)
```

For an example of using the library, refer to `example.c`

To view the library's documentation, click <a href="docs/html" target="_blank">here</a>.
