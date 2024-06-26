# cpp-learn
Coding practice

# Build instructions
- Builds with windows configurations in VS code with necessary compilers.
- pure cmake option works too. 
In root:
```
mkdir build_cmake
cd build_cmake
cmake ..
make
```

Note: It is important to pass the -DCMAKE_BUILD_TYPE=Debug while running top level cmake command rather than setting it within a component's cmake list because if the component depends on another lib, the flag will get set by that lib in the cache and your flag will not take effect.