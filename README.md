# ISZ_J
A *.dll hook (Shared Library) for ISZ-2021 which permits Jumping while "ISZ-Plugin.exe" is running.






## Building:
### Windows:
> g++ -shared -o ISZ_J.dll iszjump.cpp -luser32
### Linux/Unix:
> g++ -shared -fPIC -o ISZ_J.so iszjump.cpp -luser32
