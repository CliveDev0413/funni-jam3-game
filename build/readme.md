# How to build
This is a guide on how to build this project (if u wanna)

# Prerequisites
1. Follow the [Wiki](https://emscripten.org/docs/getting_started/downloads.html) to install all the prerequisites.
2. After making the `libray.a` file, drag it into the `lib` folder of this project.

# Building
Run the following command in this folder (cd into this folder):
`emcc -o index.js ../src/*.cpp -Os -Wall ../lib/libraylib.a -I. -I../include/ -L. -sEXPORTED_FUNCTIONS=_main -s USE_GLFW=3 -s ASYNCIFY -DPLATFORM_WEB`

Insert `-Ipath-to-raylib-h -L.` or `-Lpath-to-libraylib-a` if additional librays or headers are required.

After it sucessfully builds, make a copy of `template.html` and rename it to `index.html` then place it in this folder.