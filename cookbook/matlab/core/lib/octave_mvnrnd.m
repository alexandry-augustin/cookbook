mu=[2 3];
Sigma=[1 1.5; 1.5 3];
r=mvnrnd(mu,Sigma,100);
plot(r(:,1),r(:,2),'+');
