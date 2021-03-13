gcc.exe -fPIC -c .\trans.c
gcc.exe -shared -o libtrans.dll .\trans.o
Remove-Item .\trans.o
gcc.exe -L.\ -Wl","-rpath=.\ .\main.c -o .\test.exe -ltrans
