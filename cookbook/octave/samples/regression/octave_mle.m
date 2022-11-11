mu = 1; % Population parameter
n = 1e3; % Sample size
ns = 1e4; % Number of samples

samples = exprnd(mu,n,ns); % Population samples
means = mean(samples); % Sample means

numbins = 50;
hist(means,numbins)
h = findobj(gca,'Type','patch');
%h.FaceColor = [.8 .8 1];
hold on
%[bincounts,binpositions] = hist(means,numbins);
%binwidth = binpositions(2) - binpositions(1);
%histarea = binwidth*sum(bincounts);
%x = binpositions(1):0.001:binpositions(end);
y = normpdf(x,muhat,sigmahat);
%plot(x,histarea*y,'r','LineWidth',2)
