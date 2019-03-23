__machinekit-cnc__ is a split out repo which just contains the CNC elements of machinekit

The main reasons for stripping out the CNC stack, are 
- to simplify its maintenance 
- make it easier to change elements within the CNC side of machinekit.  
Future development with NML replacement, different interpreters etc. should be easier in a 'bare bones' repo.

Installing packages _machinekit-hal-{flavour}_ followed by _machinekit-cnc-{flavour}_ will give you a fully operational
version of machinekit.

If you want to build as a RIP, you need to clone _machinekit-hal_.

From the root of that clone run **scripts/build_with_cnc**

This will clone _machinekit-cnc_ into the root of the _machinekit-hal_ clone.

_machinekit-hal_ is built, then _machinekit-cnc_ is built with necessary artifacts from _machinekit-hal_ build copied over.

Then the required libs/binaries/scripts/configs etc are copied into _machinekit-hal_ and the environment var is set
ready to run the RIP
