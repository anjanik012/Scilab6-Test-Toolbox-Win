This repository is a test toolbox for Scilab. It requires "thirdparty" directory which can be downloaded as "external-library.zip" file from the page: https://scilab.in/fossee-scilab-toolbox. The "thirdparty" directory contains compiled library for a simple "multiplication" function written in C. After copying the "thirdparty" directory to the toolbox directory, on the scilab console run "exec builder.sce" to build the toolbox and then run "exec loader.sce" to load the toolbox.  Type "help" in the scilab console and browse through the help content of "test_toolbox". The external-library.zip file also contains separate instructions to work with MinGW on Windows OS.

This toolbox overall demonstrates
1. How to add a function defined in C in scilab
2. How to add a function defined in Scilab in Scilab
3. How to write help for the added functions
4. How to create a toolbox out of the above functions.

## Build tested on Windows 10 LTSC

Compiler:- `gcc 8.3.0`
Shell:- `Powershell`

### Build libtrans.dll & libtrans.a

```
cd .\test
.\build.ps1
```

### Run test.exe

```
.\test.exe
```

Alternatively, these steps can be easily done by GUI as well.

### Build the toolbox and load on Scilab

Open scilab console and navigate to `tbx_root`

Then do the following steps:- 

```
exec builder.sce
exec loader.sce
```

Use the toolbox.