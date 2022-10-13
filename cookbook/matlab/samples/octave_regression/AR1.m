clear
clc

% http://paulbourke.net/miscellaneous/ar/
w=load('sine4.dat');
%plot(w);
arburg(w,2);
aryule(w, 2);


x=0.0:.005:2*pi;
y=sin(x);
%plot(x, y);
arburg(y,1);

[y Fs]=wavread('sample.wav');
%sound(y, Fs);
sample=y(1:1000, 1);
%plot(sample);
ar1=arburg(sample,1);

u=1:1:1000;
for i=2:1000
    %u=[u -ar1(2)*i];
    %u(i)=-ar1(2)*u(i-1);
    u(i)=-ar1(2)^1000*i;
end
u;
clf;
hold on;
plot(sample);
%plot(u);
hold off;