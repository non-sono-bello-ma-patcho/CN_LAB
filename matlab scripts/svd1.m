d0 = 0;
d1 = 4;
m = 10*(d0+1)+d1;
% init matrix
A = init(m);
% compute transposed matrix
At = A';

%Computing singular values decompsition;
svdA = svd(A);
svdAt = svd(A');
% Computing egeinvalue:
eigAAt = eig(A*At); % A*At has dim: 14x3 3x14 -> 14x14
eigAtA = eig(At*A); % -> 3x3

% AAt and AtA has the same eigenvlaue, so that means they have the same
% characteristic polynomial(?). Also, this means AAt and AtA are
% diagonalisable => AAt = AAt' and AtA = AtA'

function M = init (n)
    M = zeros(n, 3);
    for i=1:n
        for j=1:3
           M(i,j)=(1/i)^(j-1); 
        end
    end
end
