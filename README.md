# Testing cereal C++ serialization capabilities with Qt 5.9/5.10

## Aim
This sample SHALL test means provided by [cereal](http://uscilab.github.io/cereal/), a C++ serialization library.

## Tested with
- Qt 5.9 and 5.10 on Windows/Linux/macOs

## Building and running
Make sure CMake >= 3.9 (`cmake` binary) and Qt >= 5.8 (`qmake` binary) are on the `PATH`.
```
$>  cd cereal_tests
$>  cd .. && mkdir build && cd build
$>  cmake ../cereal_tests
$>  cmake --build .
$>  ./test_cereal
```

To see the `.json` file created set a break point in `main()` before leaving the `QTemporaryDir` scope.

# Lesson learned
In order to support custom types serialization (e.g. `QDateTime` from the Qt types one might be using) we simply need

1. to define `save_minimal` and `load_minimal` in namespace `cereal`
1. make `save_minimal` return an elementary data-type or `std::string`
1. make `load_minimal` parse that same data-type

```c++
#pragma once



namespace cereal
{
    template <class Archive>
    int64_t save_minimal(Archive const&, QDateTime const& aDateTime)
    {
        return aDateTime.toUTC().toSecsSinceEpoch();
    }

    template <class Archive>
    void load_minimal(Archive const&, QDateTime& aDateTime, int64_t const& aValue)
    {
        aDateTime = QDateTime::fromSecsSinceEpoch(aValue, Qt::UTC);
    }
}
```
