d0 = 0;
d1 = 4;

% Compute size:
n = 10 * (d1+1) + d0;

% Create Jordan block:
A=diag(ones(1, n-1), 1) + eye(n);
B = createPertubate(A, n);
[Aeig, Beig, Ceig, norm1, norm2] = compute_eig_n_norm(A, B, n);
At = A';
Bt = B';
[Ateig, Bteig, Cteig, normt1, normt2] = compute_eig_n_norm(At, Bt, n);
function [Aeig, Beig, Ceig, norm1, norm2] = compute_eig_n_norm(A, B, n)
% Computing A eigenvalues:
Aeig = eig(A);

% Computing B eigenvalues:
Beig = eig(B);

% eigenvalue comparison:
Ceig = zeros(size(Beig));
for i=1:n
    Ceig(i) = (Beig(i)-Aeig(i));
end
% Computing norm:
norm1 = norm(B-A)/norm(A);
norm2 = norm(Beig-Aeig)/norm(Aeig);
end
function B = createPertubate(A, n)
    % Create pertubation:
    E = zeros(size(A));
    E(n, 1) = 10^-n;
    %Creating pertubated Matrix:
    B = A+E;
end