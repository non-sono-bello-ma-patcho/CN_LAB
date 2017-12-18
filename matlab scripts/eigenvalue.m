d0 = 0;
d1 = 4;

% Compute size:
n = 10 * (d1+1) + d0;

% Create Jordan block:
A=diag(ones(1, n-1), 1) + eye(n);
compare(A, n);


function m = compare(A, n)
    % Create pertubation:
    E = zeros(size(A));
    E(1, n) = 10^-n;

    %Creating pertubated Matrix:
    B = A+E;

    % Computing A eigenvalues:
    Aeig = eig(A);

    % Computing B eigenvalues:
    Beig = eig(B);

    % Computing norm:
    norm1 = norm(A-B)/norm(A);
    norm2 = norm(Beig-Aeig)/norm(Aeig);
end