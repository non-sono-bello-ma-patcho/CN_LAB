d0 = 0; 
d1 = 4;

% Compute size:
n = 10 * (d1+1) + d0;

% Create Jordan block:
A=diag(ones(1, n-1), 1) + eye(n);
B = createPertubate(A, n);

% Compute eigenvalue for A and B
[Ceig, norm_comparison] = compute_eig_n_norm(A, B, n);
AtA = A'*A;
BtB = B'*B;

% Compute eigenvalue for AtA and BtB
[Cteig, normt_comparison] = compute_eig_n_norm(AtA, BtB, n);

% Utility function
function [Ceig, norm_comparison] = compute_eig_n_norm(A, B, n)
% Computing A eigenvalues:
Aeig = eig(A);

% Computing B eigenvalues:
Beig = eig(B);

% eigenvalue comparison:
Ceig = zeros(size(Beig));

% compute comparison:
for i=1:n
    Ceig(i) = (Beig(i)-Aeig(i));
end
% Computing norm:
norm1 = norm(B-A)/norm(A);
norm2 = norm(Beig-Aeig)/norm(Aeig);
norm_comparison = norm1-norm2;
end
function B = createPertubate(A, n)
    % Create pertubation:
    E = zeros(size(A));
    E(n, 1) = 10^-n;
    % Create pertubated Matrix:
    B = A+E;
end