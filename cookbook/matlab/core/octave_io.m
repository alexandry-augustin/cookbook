%input

%output
'...'
disp('...')

n=5;
str = sprintf('%d', n);
disp(str);

%error('this is an error');

%example
a = input('Enter a Number to Square ');
b = a*a;
disp(['The Result is ' num2str(b)])

disp('Hit any key to continue...');
pause;
