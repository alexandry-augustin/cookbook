mu=0;
sigma=1;
x=-4:1e-3:4; 
y=normpdf(x, mu, sigma);
z=mu+sigma*randn(1000,1);

hold on;
hist(z,50);
plot(x, y)


%scatter plot
%X= 0 + 1.*randn(2,500);
%plot(X(1,:),X(2,:),'x');