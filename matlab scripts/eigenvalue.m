% Developed by: Non sono bello ma patcho
% https://github.com/non-sono-bello-ma-patcho 
% Developers:   Andrea Storace (4186140)
%               Andrea Straforini (4338710)
%               Elisa Zazzera (4380663)
d0 = 0; 
d1 = 4;

% Compute size:
n = 10 * (d1+1) + d0;

% Create Jordan block:
A=diag(ones(1, n-1), 1) + eye(n);
B = createPertubate(A, n);

% Compute eigenvalue for A and B
[Ceig, norm_comparison, T1] = compute_eig_n_norm(A, B, n);
AtA = A'*A;
BtB = B'*B;

% Compute eigenvalue for AtA and BtB
[Cteig, normt_comparison, T2] = compute_eig_n_norm(AtA, BtB, n);

writetable(T1,'eigenvalue_results.xlsx','Sheet',1,'Range','A1')
writetable(T2,'eigenvalue_results.xlsx','Sheet',1,'Range','D1')

% Utility function, computes eigenvalues of Matrix passed as input:
function [Ceig, norm_comparison, T] = compute_eig_n_norm(A, B, n)
% Computing A eigenvalues:
Aeig = eig(A);

% Computing B eigenvalues:
Beig = eig(B);

% eigenvalue comparison vector:
Ceig = zeros(size(Beig));

% compute eigenvalues comparison:
for i=1:n
    Ceig(i) = (Beig(i)-Aeig(i));
end
% Computing norms:
norm1 = norm(B-A)/norm(A);
norm2 = norm(Beig-Aeig)/norm(Aeig);

% Computing norm comparison:
norm_comparison = norm1-norm2;
T = table(Aeig, Beig, Ceig);
end
function B = createPertubate(A, n)
    % Create pertubation:
    E = zeros(size(A));
    E(n, 1) = 10^-n;
    % Create pertubated Matrix:
    B = A+E;
end