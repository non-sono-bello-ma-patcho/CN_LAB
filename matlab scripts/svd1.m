% Developed by: Non sono bello ma patcho
% https://github.com/non-sono-bello-ma-patcho 
% Developers:   Andrea Storace (4186140)
%               Andrea Straforini (4338710)
%               Elisa Zazzera (4380663)
d0 = 0;
d1 = 4;
m = 10*(d0+1)+d1;

% init matrix
A = init(m);

%Computing singular values decompsition;
%sxValues svd dxValues:
[U,svdA,V]=svd(A);
[Ut, svdAt, Vt]=svd(A');
ImA = orth(A);
ImAt = orth(A');
KerA = null(A);
KerAt = null(A');
eigA = svd(A);
eigAt = svd(A');

% Computing egeinvalue:
eigAAt = eig(A*A'); % -> 14x14
eigAtA = eig(A'*A); % -> 3x3

function M = init (n)
    M = ones(n, 3);
    for i=1:n
        for j=1:3
           M(i,j)=(i^(j-1))/(n^(j-1)); 
        end
    end
end