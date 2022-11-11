e=randn(100,1);
x=zeros(100,1);
x(1)=e(1);
alpha=0.8;
for i=2:100, x(i)=alpha*x(i-1)+e(i); end

x_n=x(2:100,1);
x_n_1=x(1:99,1);

subplot(2,1,1);
plot(x);

subplot(2,1,2);
scatter(x_n_1,x_n);