# algorithms

How to build?

1. Install vcpkg

```
git clone https://github.com/microsoft/vcpkg
./vcpkg/bootstrap-vcpkg.sh
```

2. Install deps

```
./vcpkg/vcpkg install gtest
```

3. Build with cmake

```
cmake -B build -S . "-DCMAKE_TOOLCHAIN_FILE=$(pwd)/vcpkg/scripts/buildsystems/vcpkg.cmake"
cmake --build build
```
