GOES LRIT Decompressor Library
==============================

This is a simple wrapper library for using on LRIT Rice decompression. It uses the Golomb-Rice implementation of libaec (included on most linux distros).


Linux Install Instructions
==========================

First install `libaec` in your prefered way. For Ubuntu 16.04 you can do:

```bash
sudo apt install libaec0 libaec-dev
```

Then compile the project using cmake:

```bash
mkdir build
cd build
cmake ..
make
sudo make install
sudo ldconfig
```

Puff! Installed!

Windows Compile Instructions
============================


First download `libaec` sourcecode and create the VS Solution using cmake:

```
md build
cd build
cmake ..
```

Then open the Visual Studio Solution that is created inside the folder `build` and build.

Go to this repository folder and create a folder named `libaec`. Copy from libaec repository:

* the folder `include`
* everything under `build/src/Release/`

Open the visual studio solution for this repository and hit compile.

Puff! Done!

If you prefer, binaries are available under `Releases` tab here.