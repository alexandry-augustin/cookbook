%Kronecker delta
function ret = delta(x,y)
	if x==y
		ret=1;
	else
		ret=0;
	end
end

%or
%function ret = delta(x,y)
%  ret=(x==y)