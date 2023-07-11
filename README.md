# ISZ_J
A *.dll hook (Shared Library) for ISZ-2021 which permits Jumping while "ISZ-Plugin.exe" is running.

# Features:
- A simple Dynamic Link Library *.dll *.so Shared Library for ISZ-2021 which permits Jumping in ISZ.

# Download Compiled:
- Download [Windows x64](https://github.com/ISZ-Hacker-Organization/ISZ_J/releases/download/v1.0.0/ISZ_Jx64w.dll).
- Download [Linux/Unix](https://github.com/ISZ-Hacker-Organization/ISZ_J/releases/download/v1.0.0/ISZ_Jx64l.so).


# Building:
### Windows x64:
```
> g++ -shared -o ISZ_Jx64w.dll iszjump.cpp -luser32
```
### Windows x32:
```
> g++ -m32 -shared -o ISZ_Jx32w.dll ISZ_Jx32w.o -luser32
```
### Linux/Unix:
```
> g++ -shared -fPIC -o ISZ_Jx64l.so iszjump.cpp -luser32
```
## Requirements:
> Standard Linkage Library.
> 
> C++ 14 (or Newer).
> 
> GCC or MinGW-w64


# Name Scheme:
```
ISZ_J     x64/X32        w/l          *.dll/*.so
^ Name    ^ CPU Arch     ^ OS Type    ^ Extension
```
