# range_gen
easy range generators (somewhat python ranges and generator in one) that also help avoid raw looping

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

