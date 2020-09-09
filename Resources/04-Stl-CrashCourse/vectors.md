## Vectors - Intro and Overview
#### Due: None


<sup>https://www.topcoder.com/community/competitive-programming/tutorials/power-up-c-with-the-standard-template-library-part-1/</sup>

### Vector
Vector is just an array with added functionality. Vector is the only container that is backward-compatible to native C code. 

```cpp
vector< int > v(10);

for(int i = 0; i < 10; i++) {
    v[i] = (i+1)*(i+1);
}

for(int i = 9; i > 0; i–) {
    v[i] -= v[i-1];
}
```


Declare an empty vector if integers:
```cpp
vector< int > v;
```

Declares an array of 10 empty vectors:
```cpp
vector< int > v[10];
```

Declares a vector of size 10:
```cpp
vector< int > v(10);
```

Get the current `size` of a vector:
```cpp
int elements_count = v.size();
```

Is the vector `empty`:
```cpp
bool is_empty = v.empty();

// or (not good but works)

bool is_empty = (v.size() == 0);
```

Adding items to a vector `push_back`:
```cpp
vector< int > v;

for(int i = 1; i < 1000; ++i) {
    v.push_back(rand()%100);
}
```