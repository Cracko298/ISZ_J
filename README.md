# ISZ_J
A *.dll hook (Shared Library) for ISZ-2021 which permits Jumping while "ISZ-Plugin.exe" is running.






# Building:
## Windows:
> g++ -shared -o iszjump_hook.dll iszjump.cpp -luser32
## Linux/Unix:
> g++ -shared -fPIC -o iszjump_hook.so iszjump.cpp -luser32
