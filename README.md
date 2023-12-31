# ISZ_J
- A simple Dynamic Link Library *.dll *.so Shared Library for ISZ-2021 which permits Jumping in ISZ.
- Requires the UE4 Console, and needs to be called from another Application or Script.

# Download Compiled:
- Download [Windows x64](https://github.com/ISZ-Hacker-Organization/ISZ_J/releases/download/v3.0.0/ISZ_Jx64w.dll).
- Download [Linux/Unix](https://github.com/ISZ-Hacker-Organization/ISZ_J/releases/download/v3.0.0/ISZ_Jx64l.so).
- Download the [Example Reader](https://github.com/ISZ-Hacker-Organization/ISZ_J/releases/download/v3.0.0/iszf.exe).

# Loading/Injecting:
```
> C++       LoadLibrary (Call the function MainApp).
> Python    Ctypes.CDLL (Call the function MainApp).
```
# Demonstration:
- Video Demonstration [Here](https://youtu.be/auWe3nZy-Iw) on YouTube.


# Building:
### Windows x64:
```
> g++ -shared -o ISZ_Jx64w.dll ISZ_Jx64w.cpp
```
### Windows x32:
```
> g++ -m32 -shared -o ISZ_Jx32w.dll ISZ_Jx32w.o
```
### Linux/Unix:
```
> g++ -shared -o ISZ_Jx64l.so -fPIC ISZ_Jx64w.cpp
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

# Notes:

## Features:
- Enables Jumping in ISZ-2021 (That's it).

## Update Note(s):
### Version v3.0 Released
- No More Console Window Being Shown (jumping is now seemless).
- Added some debug dialogue.
- Updated "iszf.exe" (Executes ISZ_J DLL).
