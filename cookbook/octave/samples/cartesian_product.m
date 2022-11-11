p=[1 2];
q=[1 2];
[X,Y]=meshgrid(p,q);
cart_prod=[X(:) Y(:)]; %Cartesian product
assert(cart_prod==[1 1; 1 2; 2 1; 2 2]);
assert(size(cart_prod, 1)==size(p,2)*size(q,2)) %Cardinality


p=[1 2]';
q=[1 2]';
[X,Y]=meshgrid(p,q);
cart_prod=[X(:) Y(:)]; %Cartesian product
assert(cart_prod==[1 1; 1 2; 2 1; 2 2]);
assert(size(cart_prod, 1)==size(p,1)*size(q,1)) %Cardinality
