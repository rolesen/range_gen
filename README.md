# range_gen
simple range generator library (somewhat like a python range and generator in one utility) that also can help avoid raw looping.

this is also similiar to boost::irange but with a possible extra index or custom/user types

generator object is optional if you just need to loop some indexes (ala. boost::irange but can use custom index type)

you can write a custom generator by supplying a type with operator++

note however there is no underlying or hidden container/data structure - the iterater just has some internal state that is copied (left hand side in loop is a proxy).


usages example

```
int main() {
    for (auto i : range_gen(1, 6, 100)) {
        std::cout << "index: " << i << " value " << *i << std::endl;
    }
    return 0;
}
```

prints:

```
index: 1 value 100
index: 2 value 101
index: 3 value 102
index: 4 value 103
index: 5 value 104
```

