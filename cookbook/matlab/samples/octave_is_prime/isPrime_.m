function [ret] = isPrime_(n)
  if n==0 ret=false; 
  elseif n==1 ret=false;
  else
      temp=true;
      for i=2:1:(n-1)
          if mod(n,i)==0
              temp=false;
              break;
          end
      end
      ret =temp; 
  end;
