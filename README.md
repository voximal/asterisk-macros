#Macros for Asterisk
===================

This macros have been done to help the porting of Asterisk modules.


##Requirements
------------

Any Asterisk version from 1.6 to the last one.


##Examples
--------

For Asterisk 1.6
  
  #define GET_CHAN_NAME(chan) chan->name
  
  #define GET_CHAN_NATIVEFORMATS(chan) chan->nativeformats
  
  #define GET_FRAME_CONTROL_TYPE(frame) frame->subclass


For Asterisk 13

  #define GET_CHAN_NAME(chan) ast_channel_name(chan)
  
  #define GET_CHAN_NATIVEFORMATS(chan) ast_channel_nativeformats(chan)
  
  #define GET_FRAME_CONTROL_TYPE(frame) frame->subclass.integer

##License
-------

This module is licensed under the GPLv2, feel free to redistribute, modify and
contribute changes.

A copy of the GPLv2 license text should be included with the module. If not,
check out the github repository at https://github.com/voximal/asterisk-macros
or one of its clones.

The license text can also be downloaded from:
https://www.gnu.org/licenses/gpl-2.0.txt


##Help us improve the support!
----------------------------

Found an issue? Solved one? Added something that was missing? Help us make it better!

Developed by [@voximal](https://github.com/voximal)
