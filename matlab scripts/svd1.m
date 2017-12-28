d0 = 0;
d1 = 4;
m = 10*(d0+1)+d1;
% init matrix
A = init(m);
% compute transposed matrix
At = A';

%Computing singular values decompsition;
%sxValues svd dxValues:
[U,svdA,V]=svd(A);
[Ut, svdAt, Vt]=svd(A');
ImA = orth(A);
ImAt = orth(A');
KerA = null(A);
KerAt = null(A');
% Computing egeinvalue:
eigAAt = eig(A*At); % A*At has dim: 14x3 3x14 -> 14x14
eigAtA = eig(At*A); % -> 3x3

% AAt and AtA has the same eigenvlaue, so that means they have the same
% characteristic polynomial(?). Also, this means AAt and AtA are
% diagonalisable => AAt = AAt' and AtA = AtA'


% comparison between ImA and Left Singular Values (U): same value for the
% first 3 columns;
% comparison between ImAt and Left Singluar Values (Ut): exact same value

% comparison between KerA and V: KerA nucleo banale, V 3x3 matrix
% comparison between KerAt and Vt: 

function M = init (n)
    M = ones(n, 3);
    for i=1:n
        for j=1:3
           M(i,j)=M(i,j)/(i^(j-1)); 
        end
    end
end
