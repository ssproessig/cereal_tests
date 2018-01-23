# Testing cereal C++ serialization capabilities with Qt 5.9/5.10

## Aim
This sample SHALL test means provided by cereal.

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

