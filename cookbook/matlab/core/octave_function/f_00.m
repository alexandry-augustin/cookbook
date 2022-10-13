function [ret] = f_00(n)
  %factorial
  if n==0
      ret=1;
  else
      ret=factorial(n-1)*n;
  end
