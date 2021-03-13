gcc.exe -fPIC -c -DBUILDING_EXAMPLE_DLL .\trans.c
gcc.exe -shared -o libtrans.dll .\trans.o -Wl","--out-implib,libtrans.a
Remove-Item .\trans.o
gcc.exe -L.\ -Wl","-rpath=.\ .\main.c -o .\test.exe -ltrans
