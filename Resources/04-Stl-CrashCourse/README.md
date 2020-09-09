## STL - Crash Course
#### Due: None


### Note

When making nested constructions, make sure that the “brackets” are not directly following one another – leave a blank between them.

```cpp
vector< vector< int > > CorrectDefinition;  // Remember << and >> are overloaded for std out
vector<vector<int>> WrongDefinition;        // so its confusing to the compiler when no spaces
                                            // are placed between each angle bracket
```

