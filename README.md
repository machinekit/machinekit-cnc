__machinekit-cnc__ is a split out repo which just contains the CNC elements of machinekit

It is not intended to be built as a RIP, because it has header and library dependencies upon the
HAL side of machinekit, which are found in machinekit-hal.

However this is now possible, should the need arise.
First you must build __machinekit-hal__, so that the required libs and headers are available.
Then build the __machinekit-cnc__ RIP with
$ __./autogen.sh && ./configure --with-machinekit-hal='path/to/your/machinekit-hal/build' && make -j$(nproc)__

You will need to make sure that both RIPs are in the pathspec for the current terminal session to use them

__machinekit-cnc__ is built in a CI builder with access to the required headers/libs and is available
as a package from the machinekit repo.

Installing _machinekit-hal-{flavour}_ followed by _machinekit-cnc-{flavour}_ will give you a fully operational
version of machinekit.

Given you can achieve this just by installing _machinekit_ and _machinekit-{flavour}_, this repo should be regarded as
for development only

The main reasons for stripping out the CNC stack, are 
- to simplify its maintenance 
- make it easier to change elements within the CNC side of machinekit.  
Future development with NML replacement, different interpreters etc. should be easier in a 'bare bones' repo.
