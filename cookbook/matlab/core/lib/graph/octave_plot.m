%plot()
%plot(x,y1,x,y2,x,y3)
%legend('y1','y2','y3')
%plot(x1,y1,'r:',x2,y2,'r+')

%   y yellow
%   m magenta
%   c cyan
%   r red
%   g green
%   b blue
%   w white
%   k black

%   . point
%   o circle
%   x x-mark
%   + plus
%   - solid line
%   * star
%   : dotted line
%   -. dashdot line

%examples:
%sinus
x=0:0.01:1
y=sin(2*pi*x)
plot(x,y,'-')

%multiple plots
t=0:0.1:10;
y=t;
z=t.*log(t);
x=t.*t;
plot(t,y,'-', z,'-',x,'-')
