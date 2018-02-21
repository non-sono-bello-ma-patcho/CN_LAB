% Developed by: Non sono bello ma patcho
% https://github.com/non-sono-bello-ma-patcho 
% Developers:   Andrea Storace (4186140)
%               Andrea Straforini ()
%               Elisa Zazzera ()

n=11;

% init adjency matrix
Ag = zeros(n);

% this vector contains pairs of nodes which are adjacent:
adj_nodes = [1 7 ; 1 6 ; 1 5 ; 1 2 ; 1 3 ; 1 4 ; 3 10 ; 10 11 ; 10 4 ; 4 5 ; 5 6; 5 8 ; 8 9];

% create adjency matrix:
for i=1:13
   Ag = place_simmetrically(Ag,adj_nodes(i,1), adj_nodes(i,2));
end

% Since sum(A) return a vector of lenght=n containng the sum of each
% column of the matrix, I can create a diagonal by calling diag(sum(A)) 

% Create Diagonal Matrix:
D =  diag(sum(Ag));

Di = inv(D);

% Computing Diagonal inverse:
AgDi = Ag/D;

% Computing eigenvalue:
ADeig = eig(AgDi);

% Place 1 in adjency matrix:
function [A] = place_simmetrically(A,x,y)
    A(x,y) = 1;
    A(y,x)= 1;
end

