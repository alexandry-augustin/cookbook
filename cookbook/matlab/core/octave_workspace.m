; % avoid the output to be displayed in the command windows

save
load
clc	%clear consol
clf	%clear plot (figure)

clear	%delete all non permanent variables
clear a %delete variable a

who %list variales
whos %list variables + descriptif

delete filename	%delete a file

exit %same as quit
quit %same as exit

addpath()

OCT = exist('OCTAVE_VERSION') ~= 0;           % check if we run Matlab or Octave

mfilename %current filename