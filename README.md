# ISZ_J
A *.dll hook (Shared Library) for ISZ-2021 which permits Jumping while "ISZ-Plugin.exe" is running.

# Features:
- A simple Dynamic Link Library *.dll *.so Shared Library for ISZ-2021 which permits Jumping in ISZ.

# Download Compiled:
- [Windows x64]().
- [Linux/Unix]().
- [Windows x32]().


# Building:
### Windows:
```
> g++ -shared -o ISZ_J.dll iszjump.cpp -luser32
```
### Linux/Unix:
```
> g++ -shared -fPIC -o ISZ_J.so iszjump.cpp -luser32
```
## Requirements:
> Standard Linkage Library.
> 
> C++ 14 (or Newer).
> 
> GCC or MinGW-w64
